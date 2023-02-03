#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node
{
    node *prevNode;
    int data;
    node *nextNode;
};

node *newnode(int);
node *insertfirst(node *, int);
node *insertlast(node *, int);
node *deletefirst(node *);
node *deletelast(node *);
node *rotate(node *, int, int);
void display(node *);

void main()
{
    node  *DLL = NULL;
    int choice, item;
    while(1)
    {
        printf("\nOperations on DLL - Doubly Linked List\n----------------------------------");
        printf("\n1) Insert at first\n2) Insert at last\n3) Delete first\n4) Delete last\n5) Rotate DLL\n6) Display");
        printf("\n7) Exit\n\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1 :printf("\nEnter the number : ");
                    scanf("%d", &item);
                    DLL = insertfirst(DLL, item);
                    break;
            case 2 :printf("\nEnter the number : ");
                    scanf("%d", &item);
                    DLL = insertlast(DLL, item);
                    break;
            case 3 :DLL = deletefirst(DLL);
                    break;
            case 4 :DLL = deletelast(DLL);
                    break;
            case 5 :printf("\nWhich side you want to rotate (-1 for Left or 1 for Right) : ");
                    int direction, count;
                    scanf("%d", &direction);
                    printf("\nEnter the count of position to rotate : ");
                    scanf("%d", &count);
                    DLL = rotate(DLL, direction, count);
                    break;
            case 6 :display(DLL);
                    break;
            case 7 :printf("\nEnd of Program.");
                    exit(0);
            default:printf("\nWrong option, Try again");
        }
    }
}

node *newnode(int data)
{
    node *temp = (node *) malloc(sizeof(node));
    temp->data = data;
    temp->nextNode = NULL;
    temp->prevNode = NULL;
    return temp;
}

node *insertfirst(node *head, int data)
{
    if(head == NULL)
        head = newnode(data);
    else
    {
        node *temp = newnode(data);
        temp->nextNode = head;
        head->prevNode = temp;
        head = head->prevNode;
    }
    return head;
}

node *insertlast(node *head, int data)
{
    if(head == NULL)
        head = newnode(data);
    else
    {
        node *temp = newnode(data), *hcopy = head;

        while(hcopy->nextNode != NULL)
            hcopy = hcopy->nextNode;

        hcopy->nextNode = temp;
        temp->prevNode = hcopy;
    }
    return head;
}

node *deletefirst(node *head)
{
    if(head == NULL)
        printf("\nEmpty List");
    else if(head->nextNode == NULL)
        head = NULL;
    else
    {
        head = head->nextNode;
        head->prevNode = NULL;
    }
    return head;
}

node *deletelast(node *head)
{
    if(head == NULL)
        printf("\nEmpty List");
    else if(head->nextNode == NULL)
        head = NULL;
    else
    {
        node *hcopy = head;

        while(hcopy->nextNode != NULL)
            hcopy = hcopy->nextNode;

        hcopy = hcopy->prevNode;
        hcopy->nextNode = NULL;
    }
    return head;
}

node *rotate(node *head, int dir, int count)
{
    if(head == NULL)
        printf("\nEmpty List");
    else if(count <= 0)
        printf("\nWrong count");
    else
    {
        int i;
        node *hcopy = head;
        if(dir == -1)
        {
            for(i = 0; i < count; i++)
            {    
                while(hcopy->nextNode != NULL)
                    hcopy = hcopy->nextNode;
                
                hcopy->nextNode = head;
                head->prevNode = hcopy;
                head = head->nextNode;
                head->prevNode = NULL;
                hcopy->nextNode->nextNode = NULL;
            }
        }
        else if(dir == 1)
        {
            for(i = 0; i < count; i++)
            {    
                while(hcopy->nextNode != NULL)
                    hcopy = hcopy->nextNode;
                
                hcopy->prevNode->nextNode = NULL;
                hcopy->prevNode = NULL;
                hcopy->nextNode = head;
                head->prevNode = hcopy;
                head = head->prevNode;
            }
        }
        else
            printf("\nWrong direction");
        display(head);
    }
    return head;
}

void display(node *head)
{
    if(head == NULL)
        printf("\nEmpty List");
    else
    {
        printf("\nDLL data:");
        while(head != NULL)
        {
            printf("\t%d", head->data);
            head = head->nextNode;
        }
        printf("\tEnd");
    }
}