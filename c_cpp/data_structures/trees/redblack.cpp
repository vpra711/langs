#include <iostream>

enum color
{
    BLACK,
    RED
};

struct Node
{
    int data;
    Node *parent;
    Node *leftChild;
    Node *rightChild;
    color colour;

    Node()
    {
        data = 0;
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
        colour = BLACK;
    }

    Node(int value)
    {
        data = value;
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
        colour = RED;
    }

    Node(int value, Node *parent1)
    {
        data = value;
        parent = parent1;
        leftChild = NULL;
        rightChild = NULL;
        colour = RED;
    }

    void print()
    {
        std::cout << data << "\t" << ((colour == BLACK)? "black" : "red") << std::endl;
    }
};

int insert(Node *);
void redBlackOps(Node *, int);
void travesel(Node *);
void preOrder(Node *);
void inOrder(Node *);
void postOrder(Node *);
void calculateNodes(Node *);
int calculateLeafs(Node *);
int calculateNonLeafs(Node *);

int main()
{
    Node *root;
    
    int choice = 1;

    while(choice != 10)
    {
        std::cout << "\n1) insert \n2)travesel \n3)calculate nodes"
                     "\nEnter youtr choice: " << std::endl;

        std::cin >> choice;

        switch (choice != 10)
        {
            case  1:    insert(root);          break;
            case  2:    travesel(root);        break;
            case  3:    calculateNodes(root);  break;
            case 10:    std::cout << "end of program";
        }
    }

    return 0;
}

int insert(Node *root)
{
    int value;
    Node *parent;

    std::cout << "Enter the value: ";
    std::cin >> value;

    if (root == NULL)
    {
        return Node(value, NULL);
    }

    while(root != NULL)
    {
        parent = root;

        if(root->data <= value)
        {
            root = root->rightChild;
        }
        else
        {
            root = root->leftChild;
        }
    }

    Node *leaf = new Node(value, parent);

    if(parent->data <= value)
    {
        parent->rightChild  = leaf;
    }
    else
    {
        parent->leftChild  = leaf;
    }

    return value;
}

void travesel(Node *root)
{
    int choice;

    std::cout << "1) pre-oreder \n2) in-order \n3) post-order \n";
    std::cout << "Enter the choice: ";
    std::cin >> choice;

    switch (choice)
    {
        case  1: preOrder(root);  break;
        case  2: inOrder(root);   break;
        case  3: postOrder(root); break;
        default:                  break;
    }
    
}

void preOrder(Node *root)
{
    if(root != NULL)
    {
        root->print();
        preOrder(root->leftChild);
        preOrder(root->rightChild);
    }
}

void inOrder(Node *root)
{
    if(root != NULL)
    {
        inOrder(root->leftChild);
        root->print();
        inOrder(root->rightChild);
    }
}

void postOrder(Node *root)
{
    if(root != NULL)
    {
        postOrder(root->leftChild);
        postOrder(root->rightChild);
        root->print();
    }
}

void calculateNodes(Node* root)
{
    int choice = 0;

    std::cout << "\n1) calculate leaf node \n2) calculate non-leaf nodes"
                "\nEnter your choice: ";
    std::cin >> choice;

    if(choice == 1)
    {
        std::cout << calculateLeafs(root) << std::endl;
    }
    else
    {
        std::cout << calculateNonLeafs(root) << std::endl;
    }
}

int calculateLeafs(Node *root)
{

    if(root == NULL)
    {
        return 0;
    }

    if(root->leftChild == NULL && root->rightChild == NULL)
    {
        return 1;
    }

    return calculateLeafs(root->leftChild) + calculateLeafs(root->rightChild);
}

int calculateNonLeafs(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }

    if(root->leftChild == NULL && root->rightChild == NULL)
    {
        return 0;
    }

    return 1 + calculateNonLeafs(root->leftChild) + calculateNonLeafs(root->rightChild);
}

void redBlackOps(Node *parentSibling, int value)
{
     
}