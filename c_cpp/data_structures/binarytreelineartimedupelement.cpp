#include <iostream>
#include <algorithm>

class Node
{
    public:
        int data;
        Node* leftChild;
        Node* rightChild;
};

void insertNode(Node*, int);
void travse(Node*);

int main()
{
    Node *root = new Node();
    root->data = 1;
    root->leftChild = NULL;
    root->rightChild = NULL;
    int data;
    
    while(true)
    {
        std::cout << "Enter the data: ";
        std::cin >> data;
        insertNode(root, data);
        travse(root);
    }

    return 0;
}

void insertNode(Node* parent, int data)
{
    if(parent == NULL)
    {
        parent = new Node();
        parent->data = data;
        parent->leftChild = NULL;
        parent->rightChild = NULL;
    }
    else
    {
        Node* travse = parent;
        while(travse != NULL)
        {
            parent = travse;
            if(data == travse->data)
            {
                std::cout << "Duplicate element found";
                std::exit(0);
            }
            else if(data > travse->data)
            {
                travse = travse->rightChild;
            }
            else
            {
                travse = travse->leftChild;
            }
        }

        if(data > parent->data)
        {
            parent->rightChild = new Node();
            Node* temp = parent->rightChild;
            temp->data = data;
            temp->leftChild = NULL;
            temp->rightChild = NULL;
        }
        else
        {
            parent->leftChild = new Node();
            Node* temp = parent->leftChild;
            temp->data = data;
            temp->leftChild = NULL;
            temp->rightChild = NULL;
        }
    }
}

void travse(Node* root)
{
    if(root == NULL)
        return ;
    else
    {
        travse(root->leftChild);
        std::cout << root->data;
        travse(root->rightChild);
    }
}