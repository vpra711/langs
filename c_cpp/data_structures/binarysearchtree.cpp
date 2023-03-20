#include <iostream>
#include <queue>

class Node
{
    public:
        int data;
        Node *leftNode;
        Node *rightNode;
};

Node *newnode();
void insertion(Node *);
void preoreder(Node *);
void inoreder(Node *);
void postoreder(Node *);
int search(Node *);
int depthwisetravasal(Node *);
int breathwisetravasal(Node *);

int main()
{
    Node *root = newnode();
    int option = 1;
    
    while(option != 5)
    {
        std::cout << "\nEnter the option for operation : ";
        std::cin >> option;

        switch (option)
        {
            case 1 : insertion(root);               break;
            case 2 : search(root);                  break;
            case 3 : depthwisetravasal(root);       break;
            case 4 : breathwisetravasal(root);      break;
            case 5 : exit(0);
        }
    }

    return 0;
}

Node *newnode()
{
    Node *temp = new Node;
    temp->leftNode = temp->rightNode = NULL;
    std::cout << "Enter the data: " ;
    std::cin >> temp->data;
    return temp;
}

void insertion(Node *node)
{
    Node *temp = newnode(), *parentNode;

    while(node != NULL)
    {
        parentNode = node;

        if(temp->data >= node->data)
            node = node->leftNode;
        else
            node = node->rightNode;
    }

    node = parentNode;

    if(temp->data >= node->data)
        node->leftNode = temp;
    else
        node->rightNode = temp;
}

void preorder(Node *node)
{
    if(node != NULL)
    {
        std::cout << node->data << "\t";
        preorder(node->leftNode);
        preorder(node->rightNode);
    }
}

void inorder(Node *node)
{
    if(node != NULL)
    {
        inorder(node->leftNode);
        std::cout << node->data << "\t";
        inorder(node->rightNode);
    }
}

void postorder(Node *node)
{
    if(node != NULL)
    {
        postorder(node->leftNode);
        postorder(node->rightNode);
        std::cout << node->data << "\t";
    }
}

int search(Node *node)
{
    if(node == NULL)
        return -1;

    int data;
    std::cout << "Enter data to search: ";
    std::cin >> data;

    while(node != NULL)
    {
        if(data == node->data)
        {
            std::cout << "found" << std::endl;
            return ;
        }
        else if(data > node->data)
        {
            node = node->leftNode;
        }
        else
        {
            node = node->rightNode;
        }
    }

    std::cout << "not found." << std::endl;
}

int depthwisetravasal(Node *node)
{
    if(node == NULL)
        return -1;

    int option;
    std::cout << "1.pre-order \n2.In-order \n3.post-order \nEnter the option for travasal : ";
    std::cin >> option;

    switch(option)
    {
        case 1  : preorder(node);                break;
        case 2  : inorder(node);                 break;
        case 3  : postorder(node);               break;
        default : std::cout << "\nInvaild option" << std::endl;
    }
}

int breathwisetravasal(Node *node)
{
    if(node == NULL)
        return -1;

    std::queue<Node *> nodesQ;
    nodesQ.push(node);

    while(!nodesQ.empty())
    {
        Node *temp = nodesQ.front();
        std::cout << temp->data;

        if(node->leftNode != NULL)
            nodesQ.push(temp->leftNode);

        if(node->rightNode != NULL)
            nodesQ.push(temp->rightNode);

        nodesQ.pop();
    }
}