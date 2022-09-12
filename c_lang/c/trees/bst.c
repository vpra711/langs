#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node
{
    int data;
    node *leftChildNode, *rightChildNode;
};

void preorder(node *);
void inorder(node *);
void postorder(node *);
void printnode(node *);
void search(node *);
int compare(node *, node *);
int countleafs(node *);
int countnonleafs(node *);
node *newnode(int);
node *insert(node *);
node *delete(node *);
node *returntargetnode(node *, int);

void main()
{
    node *parentNode1 = NULL;
    node *parentNode2 = NULL;
    int choice;
    while(1)
    {
        printf("\n\n---------BST Menu---------");
        printf("\n1)Insert an element\n2)Delete an element\n3)Preorder Travasal");
        printf("\n4)Inorder Travasal\n5)Postorder Travasal\n6)Search\n7)compare BSTs");
        printf("\n8)print number of nodes\n9)Exit");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1 :parentNode1 = insert(parentNode1); break;
            case 2 :parentNode1 = delete(parentNode1); break;
            case 3 :printf("\npreorder:"); preorder(parentNode1); break;
            case 4 :printf("\ninorder :"); inorder(parentNode1); break;
            case 5 :printf("\npostorder:"); postorder(parentNode1); break;
            case 6 :search(parentNode1); break;
            case 7 :if(compare(parentNode1, parentNode2) == 1)
                        printf("\nBoth BSTs are identical.");
                    else
                        printf("Both aren't identical.");
                        break;
            case 8 :printnode(parentNode1); break;
            case 9 :printf("\nEnd of Program."); exit(0);
            default:printf("\nwrong option, try again");
        }
    }
}

node *newnode(int d)
{
    node *temp = (node *) malloc(sizeof(node));
    temp->data = d;
    temp->leftChildNode = NULL;
    temp->rightChildNode = NULL;
    return temp;
}

node *insert(node *bst)
{
    int element;
    if(bst == NULL)
    {
        printf("\nEnter the data : ");
        scanf("%d", &element);
        bst = newnode(element);
    }
    else
    {
        printf("\nEnter the data : ");
        scanf("%d", &element);
        node *new = newnode(element), *bst1 = bst, *temp = bst;
        while(bst1 != NULL)
        {
            temp = bst1;
            if(bst1->data >= new->data)
                bst1 = bst1->leftChildNode;
            else
                bst1 = bst1->rightChildNode;
        }
        if(temp->data >= new->data)
            temp->leftChildNode = new;
        else
            temp->rightChildNode = new;
    }
    return bst;
}

node *delete(node *bst)
{
    if(bst == NULL)
        printf("\nTree is empty");
    else
    {
        node *target = NULL, *bsttravel = bst;
        int del;
        printf("\nEnter the number : ");
        scanf("%d", &del);

        while(bsttravel != NULL)
        {
            if(bsttravel->data == del)
                break;
            else if(bsttravel->data > del)
            {
                target = bsttravel;
                bsttravel = bsttravel->leftChildNode;
            }
            else
            { 
                target = bsttravel;
                bsttravel = bsttravel->rightChildNode;
            }
        }

        if(bsttravel != NULL && target != NULL)
        {
            if(bsttravel->leftChildNode == NULL && bsttravel->rightChildNode == NULL)
            {
                if(target->data == del)
                {
                    free(target->leftChildNode);
                    target->leftChildNode = NULL;
                }
                else
                {
                    free(target->rightChildNode);
                    target->rightChildNode = NULL;
                }
            }
            else if(bsttravel->leftChildNode == NULL && bsttravel->rightChildNode != NULL)
            {
                target->rightChildNode = bsttravel->rightChildNode;
                free(bsttravel);
            }
            else if(bsttravel->leftChildNode != NULL && bsttravel->rightChildNode == NULL)
            {
                target->leftChildNode = bsttravel->leftChildNode;
                free(bsttravel);
            }
            else
            {
                node *leftnode = bsttravel->rightChildNode;
                target = NULL;
                while(leftnode->leftChildNode != NULL)
                {
                    target = leftnode;
                    leftnode->leftChildNode;
                }
                if(target == NULL)
                {
                    bsttravel->data = leftnode->data;
                    bsttravel->rightChildNode = leftnode->rightChildNode;
                    free(leftnode);
                }
                else
                {
                    bsttravel->data = leftnode->data;
                    free(target->leftChildNode);
                    target->leftChildNode = NULL;
                }
            }
        }
        else if(bsttravel != NULL && target == NULL)
        {
            if(bsttravel->leftChildNode == NULL && bsttravel->rightChildNode == NULL)
                return NULL;
            else
            {
                node *leftnode = bsttravel->rightChildNode;
                while(leftnode->leftChildNode != NULL)
                {
                    target = leftnode;
                    leftnode->leftChildNode;
                }
                if(target == NULL)
                {
                    bsttravel->data = leftnode->data;
                    bsttravel->rightChildNode = leftnode->rightChildNode;
                    free(leftnode);
                }
                else
                {
                    bsttravel->data = leftnode->data;
                    free(target->leftChildNode);
                    target->leftChildNode = NULL;
                }
            }
        }
        else
            printf("\nThe element is not found");
    }
    return bst;
}

void preorder(node *tree)
{
    if(tree == NULL)
        return ;
    else
    {
        printf(" %d", tree->data);
        preorder(tree->leftChildNode);
        preorder(tree->rightChildNode);
    }
}

void inorder(node *tree)
{
    if(tree == NULL)
        return ;
    else
    {
        inorder(tree->leftChildNode);
        printf(" %d", tree->data);
        inorder(tree->rightChildNode);
    }
}

void postorder(node *tree)
{
    if(tree == NULL)
        return ;
    else
    {
        postorder(tree->leftChildNode);
        postorder(tree->rightChildNode);
        printf(" %d", tree->data);
    }
}

void search(node *tree)
{
    if(tree == NULL)
        printf("\nTree is empty.");
    else
    {
        int key;
        printf("\nEnter the element to search : ");
        scanf("%d", &key);
        while(tree != NULL)
        {
            if(tree->data == key)
            {
                printf("\nThe element is found.");
                return ;
            }
            else if(tree->data > key)
                tree = tree->leftChildNode;
            else
                tree = tree->rightChildNode;
        }
        printf("\nThe element is not found.");
    }
}

int compare(node *pN1, node *pN2)
{
    if(pN1 == NULL && pN2 == NULL)
        return 1;
    else if((pN1 == NULL && pN2 != NULL) || (pN1 != NULL && pN2 == NULL))
        return 0;
    else
    {
        if(pN1->data == pN2->data && compare(pN1->leftChildNode, pN2->leftChildNode)
            && compare(pN1->rightChildNode, pN2->rightChildNode))
            return 1;
        else
            return 0;
    }
}

void printnode(node *bst)
{
    if(bst == NULL)
        printf("\nEmpty tree");
    else
    {
        int leafs = countleafs(bst), nonleafs = countnonleafs(bst);
        int totalNodes = leafs + nonleafs;
        printf("\nNumber of non-leafs in the tree : %d", nonleafs);
        printf("\nNumber of leafs in the tree : %d", leafs);
        printf("\nTotal : %d", totalNodes);
    }
}

int countleafs(node *tree)
{
    if(tree == NULL)
        return 0;
    else if(tree->leftChildNode == NULL && tree->rightChildNode == NULL)
        return 1;
    else 
        return countleafs(tree->leftChildNode) + countleafs(tree->rightChildNode);
}

int countnonleafs(node* tree)
{
    if (tree == NULL || (tree->leftChildNode == NULL && tree->rightChildNode == NULL))
        return 0;
 
    return 1 + countnonleafs(tree->leftChildNode) + countnonleafs(tree->rightChildNode);
}