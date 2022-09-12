#include <iostream>
#include <algorithm>

class node
{
    public:
        int data;
        node* leftChild;
        node* rightChild;
};

void insertNode(node*, int);
void travse(node*);

int main()
{
    node *root = new node();
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

void insertNode(node* parent, int data)
{
    if(parent == NULL)
    {
        parent = new node();
        parent->data = data;
        parent->leftChild = NULL;
        parent->rightChild = NULL;
    }
    else
    {
        node* travse = parent;
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
            parent->rightChild = new node();
            node* temp = parent->rightChild;
            temp->data = data;
            temp->leftChild = NULL;
            temp->rightChild = NULL;
        }
        else
        {
            parent->leftChild = new node();
            node* temp = parent->leftChild;
            temp->data = data;
            temp->leftChild = NULL;
            temp->rightChild = NULL;
        }
    }
}

void travse(node* root)
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