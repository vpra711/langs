#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

struct node
{
    int data;
    node *nextNode;
};

node *newnode(int);
int countelement(node *);
node *insertfirst(node *, int);
node *insertlast(node *, int);
node *deletefirst(node *);
node *deletelast(node *);
node *rotate(node *, int, int);
void display(node *);

void main()
{
    node *CLL = NULL;
    int choice, item;
    while(1)
    {
        printf("\n\nOperations on CLL - Circular Linked List\n------------------------------------------");
        printf("\n1) Insert at first\n2) Insert at last\n3) Delete first\n4) Delete last\n5) Rotate CLL\n6) Display CLL");
        printf("\n7) Exit\n\nEnter your choice : ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1 :printf("\nEnter the number : ");
                    scanf("%d", &item);
                    CLL = insertfirst(CLL, item);
                    break;
            case 2 :printf("\nEnter the number : ");
                    scanf("%d",&item);
                    CLL = insertlast(CLL, item);
                    break;
            case 3 :CLL = deletefirst(CLL);
                    break;
            case 4 :CLL = deletelast(CLL);
                    break;
            case 5 :printf("\nWhich side you wnat to rotate (-1 for left | 1 for right): ");
                    int direction, count;
                    scanf("%d", &direction);
                    printf("\nEnter the count of position to rotate : ");
                    scanf("%d", &count);
                    CLL = rotate(CLL, direction, count);
                    break;
            case 6 :display(CLL);
                    break;
            case 7 :printf("\nEnd of program.");
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
    return temp;
}

int countelement(node *tail)
{
    int count = 0;
    node *head = tail->nextNode;

    while(head != tail)
    {
        count++;
        head = head->nextNode;
    }

    count++;
    return count;
}

node *insertfirst(node *tail, int data)
{
    if(tail == NULL)
    {
        tail = newnode(data);
        tail->nextNode = tail;
    }
    else
    {
        node *temp = tail->nextNode;
        node *head = newnode(data);
        tail->nextNode = head;
        head->nextNode = temp;             
    }
    return tail;
}

node *insertlast(node *tail, int data)
{
    if(tail == NULL)
    {
        tail = newnode(data);
        tail->nextNode = tail;
    }
    else
    {
        node *head = tail->nextNode;
        tail->nextNode = newnode(data);
        tail = tail->nextNode;
        tail->nextNode = head;
    }
    return tail;
}

node *deletefirst(node *tail)
{
    if(tail == NULL)
        printf("\nEmpty List");
    else if(tail == tail->nextNode)
        tail = NULL;
    else
        tail->nextNode = tail->nextNode->nextNode;
    return tail;
}

node *deletelast(node *tail)
{
    if(tail == NULL)
        printf("\nEmpty List");
    else if(tail == tail->nextNode)
        tail = NULL;
    else
    {
        node *temp = tail->nextNode;
        int count = countelement(tail), i;
        for(i = 0; i < count-1; i++)
            tail = tail->nextNode;
        tail->nextNode = tail->nextNode->nextNode;
    }
    return tail;
}

node *rotate(node *list, int dir, int count)
{
    if(list == NULL)
        printf("\nEmpty List");
    else if(count <= 0)
        printf("\nWrong count");
    else
    {
        int i, j, noofelement = countelement(list);
        if(dir == -1)
            for(i = 0; i < count; i++)
                list = list->nextNode;    
        else if(dir == 1)
            for(i = 0; i < count; i++)
                for(j = 0; j < noofelement-1; j++)
                    list = list->nextNode;
        else
            printf("\nWrong direction");
        display(list);
    }
    return list;
}

void display(node *list)
{
    if(list == NULL)
        printf("\nEmpty List");
    else
    {
        list = list->nextNode;
        int count = countelement(list), i;
        printf("\nCLL data :");

        for(i = 0; i < count; i++)
        {
            printf("\t%d",list->data);
            list = list->nextNode;
        }
        printf("\tEnd");
    }
}