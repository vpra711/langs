#include <iostream>
#include <string>
#include <vector>

class directory
{
    public:

        std::string name;
        directory* parent;
        directory* next;
        directory* subDir;
        std::string content;
        bool isFile;

        directory(std::string name, directory* parent)
        {
            this->name = name;
            this->parent = parent;
            this->next = NULL;
            this->subDir = NULL;
            this->content = "";
            this->isFile = false;
        }

        directory(std::string name, std::string content, directory* parent, bool isFile)
        {
            this->name = name;
            this->parent = parent;
            this->next = NULL;
            this->subDir = NULL;
            this->content = content;
            this->isFile = isFile;
        }
};

void mkdir(std::string name, directory* currdir);
void list(directory* currdir);
directory* changeDir(std::string name, directory* currdir);
void addContent(std::string name, std::string content, directory* currdir);
void readContent(std::string name, directory* currdir);
directory* find(std::string name, directory* currdir);
void printPath(directory* currDir);
void remove(std::string name, directory* currDir);
void removeItem(directory* currDir);
void removeDirectory(directory* currDir);


std::vector<std::string> strSplit(std::string, std::string);

int main()
{
    directory* root = new directory("root", NULL);
    directory* currDir = root;
    std::string command;

    while(1)
    {
        std::cout << std::endl;
        printPath(currDir);
        std::cout << std::endl;
        std::cout << ">> ";
        std::getline(std::cin, command);

        std::vector<std::string> com = strSplit(command, " ");

        if(com.at(0) == "mkdir")
        {
            mkdir(com.at(1), currDir);
        }
        else if(com.at(0) == "list" || com.at(0) == "ls")
        {
            list(currDir->subDir);
        }
        else if(com.at(0) == "cd")
        {
            currDir = changeDir(com.at(1), currDir);
        }
        else if(com.at(0) == "whereami")
        {
            std::cout << currDir->name << std::endl;
        }
        else if(com.at(0) == "pwd")
        {
            changeDir("..", currDir);
        }
        else if(com.at(0) == "ctr")
        {
            currDir = root;
        }
        else if(com.at(0) == "exit")
        {
            std::exit(0);
        }
        else if(com.at(0) == "touch" || com.at(0) == "addcontent")
        {
            addContent(com.at(1), com.at(2), currDir);
        }
        else if(com.at(0) == "read" || com.at(0) == "readcontent")
        {
            readContent(com.at(1), currDir);
        }
        else if(com.at(0) == "rm" || com.at(0) == "remove")
        {
            remove(com.at(1), currDir);
        }
        else if(com.at(0) == "find" || com.at(0) == "search")
        {
            std::cout << find(com.at(1), currDir);
        }
        else if(com.at(0) == "help")
        {
            std::cout << "Available comments :" << std::endl;
            std::cout << "  mkdir" << std::endl;
            std::cout << "  list" << std::endl;
            std::cout << "  cd" << std::endl;
            std::cout << "  wherami" << std::endl;
            std::cout << "  pwd" << std::endl;
            std::cout << "  ctr - change to root" << std::endl;
            std::cout << "  addcontent | touch" << std::endl;
            std::cout << "  read | readcontent" << std::endl;
            std::cout << "  find" << std::endl;
            std::cout << "  rm" << std::endl;
            std::cout << "  echo | print" << std::endl;
            std::cout << "  path" << std::endl;
            std::cout << "  clear | cls" << std::endl;
            std::cout << "  exit" << std::endl;
        }
        else if(com.at(0) == "path")
        {
            printPath(currDir);
        }
        else if(com.at(0) == "clear" || com.at(0) == "cls")
        {
            system("clear");
        }
        else if(com.at(0) == "echo" || com.at(0) == "print")
        {
            std::cout << com.at(1) << std::endl;
        }
        else
        {
            std::cout << "Command not found. type 'help' to get more info" << std::endl;
        }
    }

    return 0;
}

void mkdir(std::string name, directory* currentDir)
{
    directory* subDir = find(name, currentDir);

    if(!subDir)
    {
        directory* newDir = new directory(name, currentDir);
        directory* subDir = currentDir->subDir;

        if(subDir == NULL)
        {
            currentDir->subDir = newDir;
        }
        else
        {
            while(subDir->next != NULL)
            {
                subDir = subDir->next;
            }
            
            subDir->next = newDir;
        }
    }
    else
    {
        std::cout << "directory exist" << std::endl;
    }
    
}

directory* changeDir(std::string name, directory* currDir)
{
    bool found = false;
    directory* parent = currDir;

    if(name == "..")
    {
        if(currDir->parent != NULL)
        {
            found = true;
            currDir = currDir->parent;
        }
    }
    else
    {
        currDir = find(name, currDir);

        if((currDir != NULL) && (!currDir->isFile))
        {
            found = true;
        }
    }

    if(found)
    {
        return currDir;
    }
    else
    {
        std::cout << "not found" << std::endl;
        return parent;
    }
}

void list(directory* currDir)
{
    if(currDir == NULL)
    {
        std::cout << "nothing" << std::endl;
    }
    else
    {
        std::cout << "name\ttype" << std::endl;
        std::cout << "----\t----" << std::endl;

        while(currDir != NULL)
        {
            std::cout << currDir->name;

            if(currDir->isFile)
            {
                std::cout << "\tf";
            }
            else
            {
                std::cout << "\td";
            }

            std::cout << std::endl;
            currDir = currDir->next;
        }
    }
}

std::vector<std::string> strSplit(std::string str, std::string delimeter)
{
    std::vector<std::string> parts;
    int index = str.find(delimeter);
    int deliLength = delimeter.length();

    if(deliLength == 0 || str.length() == 0)
    {
        return parts;
    }

    while(index != -1)
    {
        parts.push_back(str.substr(0, index));
        str = str.substr(index + deliLength);
        index = str.find(delimeter);
    }

    parts.push_back(str);

    return parts;
}

void addContent(std::string name, std::string content, directory* currDir)
{
    directory* subDir = find(name, currDir);

    if(!subDir)
    {
        directory* newFile = new directory(name, content, currDir, true);
        directory* subDir = currDir->subDir;

        if(subDir == NULL)
        {
            currDir->subDir = newFile;
        }
        else
        {
            while(subDir->next != NULL)
            {
                subDir = subDir->next;
            }
            
            subDir->next = newFile;
        }
    }
    else
    {
        if(subDir->isFile)
        {
            subDir->content += content;
        }
        else
        {
            std::cout << "it's a directory" << std::endl;
        }
    }
}

void readContent(std::string name, directory* currDir)
{
    directory* subDir = find(name, currDir);

    if(subDir)
    {
        if(subDir->isFile)
        {
            std::cout << subDir->content << std::endl;
            return ;
        }
        else
        {
            std::cout << "it's a directory" << std::endl;
        }
    }
    else
    {
        std::cout << "file not exist" << std::endl;
    }
}

directory* find(std::string name, directory* currDir)
{
    directory* subDir = currDir->subDir;

    while(subDir != NULL)
    {
        if(name == subDir->name)
        {
            return subDir;
        }

        subDir = subDir->next;
    }

    return NULL;
}

void printPath(directory* currDir)
{
    if(currDir == NULL)
        return ;

    printPath(currDir->parent);

    std::cout << currDir->name << "\\" ;
}

void remove(std::string name, directory* currDir)
{
    directory* subDir = find(name, currDir);

    if(subDir)
    {
        subDir = currDir->subDir;

        if(subDir->name == name)
        {
            currDir->subDir = currDir->subDir->next;
            removeItem(subDir);
        }
        else
        {
            while(subDir->next != NULL)
            {
                if(name == subDir->next->name)
                {
                    directory* del = subDir->next;
                    subDir->next = subDir->next->next;
                    removeItem(del);
                    return ;
                }

                subDir = subDir->next;
            }
        }
    }
    else
    {
        std::cout << "directory / file not exist" << std::endl;
    }
}

void removeItem(directory* currDir)
{
    removeDirectory(currDir->subDir);
    std::cout << "delete : " << currDir->name << std::endl;
    delete currDir;
}

void removeDirectory(directory* currDir)
{
    if(currDir == NULL)
        return ;

    removeDirectory(currDir->next);
    removeDirectory(currDir->subDir);

    std::cout << "delete : " << currDir->name << std::endl;
    delete currDir;
}