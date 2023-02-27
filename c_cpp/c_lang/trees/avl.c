#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node
{
    int data, balFac;
    node *leftNode, *rightNode;
};

void travesal(node *);
void preorder(node *);
void inorder(node *);
void postorder(node *);
void calheight(node *);
void search(node *);
int height(node *);
node *newnode();
node *insert(node *);
node *update(node *);
node *leftrotate(node *);
node *rightrotate(node *);
node *delete(node *);

void main()
{
    int choice = 0;
    node *avlRoot = NULL;
    while(1)
    {
        printf("\n--------------------------------");
        printf("\n1) insert\n2) delete\n3) travesal\n4) search\n5) exit\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1 : avlRoot = insert(avlRoot); break;
            case 2 : avlRoot = delete(avlRoot); break;
            case 3 : travesal(avlRoot); break;
            case 4 : search(avlRoot); break;
            case 5 : exit(0);
            default: printf("\nWrong option!, try again");
        }
    }
}

node *newnode()
{
    node *temp = (node *) malloc(sizeof(node));
    printf("\nEnter the data : ");
    scanf("%d", &temp->data);
    temp->balFac = 1;
    temp->leftNode = temp->rightNode = NULL;
    return temp; 
}

node *insert(node *root)
{
    if(root == NULL)
        root = newnode();
    else
    {
        node *temp = newnode(), *tempRoot = root, *tempTrack = tempRoot;
        while(tempRoot != NULL)
        {
            tempTrack = tempRoot;
            if(temp->data > tempRoot->data)
                tempRoot = tempRoot->rightNode;
            else
                tempRoot = tempRoot->leftNode;
        }

        if(temp->data > tempTrack->data)
            tempTrack->rightNode = temp;
        else
            tempTrack->leftNode = temp;
    }
    calheight(root);
    root = update(root);
    calheight(root);
    return root;
}

void travesal(node *root)
{
    if(root == NULL)
    {
        printf("\nTree is empty.");
        return ;
    }
    int choice = 0;
    printf("\n1) preorder\n2) inorder\n3) postorder\nEnter your choice : ");
    scanf("%d", &choice);
    switch (choice)
    {
        case 1: printf("\npreorder : ");
                preorder(root);
                break;
        case 2: printf("\ninorder : ");
                inorder(root);
                break;
        case 3: printf("\npostorder : ");
                postorder(root);
                break;
        default: printf("\nwrong choice.");
    }
}

void preorder(node *currentNode)
{
    if(currentNode == NULL)
        return ;
    printf(" %d", currentNode->data);
    preorder(currentNode->leftNode);
    preorder(currentNode->rightNode);
}

void inorder(node *currentNode)
{
    if(currentNode == NULL)
        return ;
    inorder(currentNode->leftNode);
    printf(" %d", currentNode->data);
    inorder(currentNode->rightNode);
}

void postorder(node *currentNode)
{
    if(currentNode == NULL)
        return ;
    postorder(currentNode->leftNode);
    postorder(currentNode->rightNode);
    printf(" %d", currentNode->data);
}

void calheight(node *currentNode)
{
    if(currentNode == NULL)
        return ;
    
    calheight(currentNode->leftNode);
    calheight(currentNode->rightNode);
    currentNode->balFac = height(currentNode->leftNode) - height(currentNode->rightNode);
}

void search(node *root)
{
    if(root == NULL)
        printf("\nTree is empty");
    else
    {
        int info = 0;
        printf("\nEnter the element to search : ");
        scanf("%d", &info);
        while(root != NULL)
        {
            if(root->data == info)
            {
                printf("\nThe element is found");
                return ;
            }
            else if(root->data > info)
                root = root->leftNode;
            else
                root = root->rightNode;
        }
        printf("\nThe element is not found");
    }
}

int height(node *currentNode)
{
    if(currentNode == NULL)
        return 0;
    
    int left = height(currentNode->leftNode);
    int right = height(currentNode->rightNode);

    if(left > right)
        return left + 1;
    else
        return right + 1;
}

node *update(node *currentNode)
{
    if(currentNode == NULL)
        return NULL;

    currentNode->leftNode = update(currentNode->leftNode);
    currentNode->rightNode = update(currentNode->rightNode);

    if(currentNode->balFac > 1)
        return leftrotate(currentNode);
    else if(currentNode->balFac < -1)
        return rightrotate(currentNode);
    
    return currentNode;
}

node *leftrotate(node *currentNode)
{
    node *temp = currentNode->rightNode;
    currentNode->rightNode = temp->leftNode;
    temp->leftNode = currentNode;
    return temp;
}

node *rightrotate(node *currentNode)
{
    node *temp = currentNode->leftNode;
    currentNode->leftNode = temp->rightNode;
    temp->rightNode = currentNode;
    return temp;
}

node *delete(node *root)
{
    if(root == NULL)
        printf("\nTree is empty");
    else
    {
        int del;
        printf("\nEnter the element to delete : ");
        scanf("%d", &del);
        node *trackerNode = root, *targetNode = root;

        while(trackerNode != NULL)
        {
            if(trackerNode->data == del)
                break;
            else if(trackerNode->data < del)
            {
                targetNode = trackerNode;
                trackerNode = trackerNode->rightNode;
            }
            else
            {
                targetNode = trackerNode;
                trackerNode = trackerNode->leftNode;
            }
        }

        if(trackerNode != NULL && targetNode != NULL)
        {
            if(trackerNode->leftNode == NULL && trackerNode->rightNode == NULL)
            {
                if(targetNode->leftNode->data == del)
                    targetNode->leftNode = NULL;
                else
                    targetNode->rightNode = NULL;
            }
            else if(trackerNode->leftNode == NULL && trackerNode->rightNode != NULL)
            {
                if(targetNode->leftNode->data == del)
                    targetNode->leftNode = trackerNode->rightNode;
                else
                    targetNode->rightNode = trackerNode->rightNode;
            }
            else if(trackerNode->leftNode != NULL && trackerNode->rightNode == NULL)
            {
                if(targetNode->leftNode->data == del)
                    targetNode->leftNode = trackerNode->leftNode;
                else
                    targetNode->rightNode = trackerNode->leftNode;
            }
            else
            {
                node *inorderSuccesser = trackerNode->rightNode;
                targetNode = NULL;

                while(inorderSuccesser->leftNode != NULL)
                {
                    targetNode = inorderSuccesser;
                    inorderSuccesser = inorderSuccesser->leftNode;   
                }

                trackerNode->data = inorderSuccesser->data;

                if(targetNode == NULL)
                    trackerNode->rightNode = inorderSuccesser->rightNode;
                else
                    targetNode->leftNode = NULL;

                free(inorderSuccesser);
            }
        }
        else if(trackerNode == NULL && targetNode != NULL)
        {
            if(targetNode->leftNode == NULL && targetNode->rightNode == NULL)
                return NULL;
            else
            {
                node *inorderSuccessor = trackerNode->rightNode;
                targetNode = NULL;

                while(inorderSuccessor->leftNode != NULL)
                {
                    targetNode = inorderSuccessor;
                    inorderSuccessor = inorderSuccessor->leftNode;
                }

                trackerNode->data = inorderSuccessor->data;

                if(targetNode == NULL)
                    trackerNode->rightNode = inorderSuccessor->rightNode;
                else
                    targetNode->leftNode = NULL;

                free(inorderSuccessor);
            }
        }
        else
            printf("\nThe element does not exist!");
    }
    calheight(root);
    root = update(root);
    calheight(root);
    return root;
}