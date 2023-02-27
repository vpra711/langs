#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node;

struct node
{
    char name[10];
    long number;
    int balfact;
    node *leftChild, *rightChild;
};

node *newnode();
node *insert(node *);
node *rr(node *);
node *ll(node *);
node *checkorder(node *);
int height(node *);
void inorder(node *);
void search(node *);
void updatebalfact(node *);

void main()
{
    int choice;
    node *dir = NULL;
    while(1)
    {
        printf("\n\n------------Main menu---------------");
        printf("\n1)Insert (Add phone)\n2)Inorder (Print_dir)\n3)Search\n4)Height\n5)Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 0: dir = NULL; printf("\nCleared successfully"); break;
            case 1: dir = insert(dir); break;
            case 2: inorder(dir); break;
            case 3: search(dir); break;
            case 4: printf("\nHeight of AVL tree is : %d",height(dir)); break;
            case 5: printf("\nEnd of program."); exit(0);
            default:printf("\nWrong option, Try again");
        }
    }
}

node *newnode()
{
    node *temp = (node *) malloc(sizeof(node));
    printf("\nEnter the name : ");
    scanf("%s", &temp->name);
    printf("\nEnter the number : ");
    scanf("%ld", &temp->number);
    temp->balfact = 1;
    temp->leftChild = temp->rightChild = NULL;
    return temp;
}

node *insert(node *avl)
{
    if(avl == NULL)
        avl = newnode();
    else
    {
        node *avlc = avl, *newdir = newnode(), *target = NULL;
        while(avlc != NULL)
        {
            target = avlc;
            if(strcmp(newdir->name, avlc->name) <= 0)
                avlc = avlc->leftChild;
            else
                avlc = avlc->rightChild;
        }
        if(strcmp(newdir->name, target->name) <= 0)
            target->leftChild = newdir;
        else
            target->rightChild = newdir;
    }
    updatebalfact(avl);
    avl = checkorder(avl);
    updatebalfact(avl);
    return avl;
}

void inorder(node *avl)
{
    if(avl == NULL)
        return;
    else
    {
        inorder(avl->leftChild);
        printf("\nName : %s\tMobile Number : %ld", avl->name, avl->number);
        inorder(avl->rightChild);
    }
}

void search(node *avl)
{
    if(avl == NULL)
        return;
    else
    {
        char name[10];
        printf("\nEnter the name : ");
        scanf("%s", &name);
        while(avl != NULL)
        {
            if(strcmp(name, avl->name) == 0)
            {
                printf("\nDetails - Name : %s, Mobile Number : %ld", avl->name, avl->number);
                return ;
            }
            else if(strcmp(name, avl->name) < 0)
                avl = avl->leftChild;
            else
                avl = avl->rightChild;
        }
        printf("\nName is not found");
    }
}

int height(node *avl)
{
    if(avl == NULL)
        return 0;

    int left = height(avl->leftChild);
    int right = height(avl->rightChild);

    if(left > right)
        return left + 1;
    else
        return right + 1;
}

node *ll(node *llnode)
{
    node *temp = llnode->rightChild;
    llnode->rightChild = temp->leftChild;
    temp->leftChild = llnode;
    return temp;
}

node *rr(node *rrnode)
{
    node *temp = rrnode->leftChild;
    rrnode->leftChild = temp->rightChild;
    temp->rightChild = rrnode;
    return temp;
}

node *checkorder(node *avl)
{
    if(avl == NULL)
        return NULL;

    avl->leftChild = checkorder(avl->leftChild);

    if(avl->balfact < -1)
        return ll(avl);
    else if(avl->balfact > 1)
        return rr(avl);
        
    avl->rightChild = checkorder(avl->rightChild);

    return avl;
}

void updatebalfact(node *avl)
{
    if(avl == NULL)
        return ;
    updatebalfact(avl->leftChild);
    updatebalfact(avl->rightChild);
    avl->balfact = height(avl->leftChild) - height(avl->rightChild);
}