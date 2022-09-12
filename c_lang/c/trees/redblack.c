#include <stdio.h>
#include <stdbool.h>

typedef struct node node;

struct node
{
    int data;
    bool color;
    node *leftNode, *rightNode;
};

node *newnode();
node *insert(node *);
node *delete(node *);
void search(node *);
int height(node *);

void main()
{
    int choice = 0;
    node *rb = NULL;
    while(1)
    {
        printf("\n1) insert\n2) delete\n3) search\n4) travesal\n5) exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1 : rb = insert(rb); break;
            case 2 : rb = delete(rb); break;
            case 3 : search(rb); break;
            case 4 : travesal(rb); break;
            case 5 : printf("\nEnd of the program"); exit(0);
            default: printf("\nWrong option, try again");
        }
    }
}

node *newnode()
{
    node *temp = (node *) malloc(sizeof(node));
    printf("\nEnter the data : ");
    scanf("%d", temp->data);
    temp->color = 1;
    temp->leftNode = temp->rightNode = NULL;
    return temp;
}

node *insert(node *root)
{ 
    node *temp = newnode();
    if(root == NULL)
        temp->color = 0;
    else
    {
        temp->color = 1;
        
    }

    return temp;

}

void search(node *root)
{
    if (root == NULL)
        return ;
    int data = 0;
    printf("\nEnter the element to search : ");
    scanf("%d", &data);
    
    while(root != NULL)
    {
        if(root->data == data)
        {
            printf("\nThe element is found");
            break;
        }
        else if(root->data > data)
            root = root->leftNode;
        else
            root = root->rightNode;
    }
    printf("\nThe element not found");
}