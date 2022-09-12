#include <iostream>
#include <queue>

class binarySearchTree
{
    public:
        int data;
        binarySearchTree *leftNode;
        binarySearchTree *rightNode;
};

binarySearchTree *newnode();
void insertion(binarySearchTree *);
void preoreder(binarySearchTree *);
void inoreder(binarySearchTree *);
void postoreder(binarySearchTree *);
void search(binarySearchTree *);
void depthwisetravasal(binarySearchTree *);
void breathwisetravasal(binarySearchTree *);

int main()
{
    binarySearchTree *root = newnode();
    int option = 1;
    while(option == 1 || option == 2 || option == 3 || option == 4)
    {
        std::cout << "\nEnter the option for operation : ";
        std::cin >> option;
        switch (option)
        {
            case 1 : insertion(root); break;
            case 2 : search(root); break;
            case 3 : depthwisetravasal(root); break;
            case 4 : breathwisetravasal(root);  
        }
    }
    return 0;
}

binarySearchTree *newnode()
{
    binarySearchTree *temp = new binarySearchTree;
    temp->leftNode = temp->rightNode = NULL;
    std::cout << "Enter the data to be inserted : " ;
    std::cin >> temp->data;
    return temp;
}

void insertion(binarySearchTree *node)
{
    std::queue<binarySearchTree *> tempQ;
    binarySearchTree *temp = newnode();
    while(node != NULL)
    {
        tempQ.push(node);
        if(temp->data >= node->data)
            node = node->leftNode;
        else
            node = node->rightNode;
    }
    node = tempQ.back();
    if(temp->data >= node->data)
        node->leftNode = temp;
    else
        node->rightNode = temp;
}

void preorder(binarySearchTree *node)
{
    if(node == NULL)
        return;
    else
    {
        std::cout << node->data << "\t";
        preorder(node->leftNode);
        preorder(node->rightNode);
    }
}

void inorder(binarySearchTree *node)
{
    if(node == NULL)
        return;
    else
    {
        inorder(node->leftNode);
        std::cout << node->data << "\t";
        inorder(node->rightNode);
    }

}

void postorder(binarySearchTree *node)
{
    if(node == NULL)
        return;
    else
    {
        postorder(node->leftNode);
        postorder(node->rightNode);
        std::cout << node->data << "\t";
    }

}

void search(binarySearchTree *node)
{
    if(node == NULL)
        std::cout << "Tree is empty" << std::endl;
    else
    {
        int data;
        std::cout << "Enter the element to be searched : ";
        std::cin >> data;
        while(node != NULL)
        {
            if(data == node->data)
            {
                std::cout << "The element is :" << node->data << std::endl;
                return ;
            }
            else if(data > node->data)
                node = node->leftNode;
            else
                node = node->rightNode;
        }
        std::cout << "The element is not found." << std::endl;
    }
}

void depthwisetravasal(binarySearchTree *node)
{
    if(node == NULL)
        std::cout << "Tree empty" << std::endl;
    else
    {
        int option;
        std::cout << "1.pre-order \n2.In-order \n3.post-order \nEnter the option for travasal : ";
        std::cin >> option;
        switch(option)
        {
            case 1 : preorder(node); break;
            case 2 : inorder(node); break;
            case 3 : postorder(node); break;
            default : std::cout << "\nInvaild option" << std::endl;
        }
    }
}

void breathwisetravasal(binarySearchTree *node)
{
    if(node == NULL)
        std::cout << "Tree empty" << std::endl;
    else
        {
            
        } 
}