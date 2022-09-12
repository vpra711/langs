#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node node;

struct node
{
  node *next;
  char data[5];
};

void insertFirst(node *linklist, char *item)
{
    node *newNode = (node *) malloc(sizeof(node));
    strcpy(newNode->data, item);
    newNode -> next = linklist -> next;
    linklist -> next = newNode;
}

void insertMiddle(node *linklist, char *item1, char *item2)
{
    node *temp = linklist;
    node *checkPoint = NULL;

    while(temp)
    {
        if(strcmp(temp->data, item1))
            temp = temp->next;
        else
        {
            checkPoint = temp;
            temp = temp->next;
        }
    }

    if(checkPoint == NULL)
        printf("\nThe element not found");
    else
    {
        temp = checkPoint->next;
        node *newNode = (node *) malloc(sizeof(node));
        strcpy(newNode->data, item2);
        newNode->next = temp;
        checkPoint->next = newNode;
    }
}

void insertLast(node *linklist, char *item)
{
    node *newNode = (node *) malloc(sizeof(node));
    strcpy(newNode->data, item);
    node *temp = linklist;

    while(temp->next)
        temp = temp -> next;   

    temp -> next = newNode;
    newNode -> next = NULL;
}

char *deleteFirst(node *linklist)
{
    node *temp = linklist -> next;
    node *temp1 = (node *) malloc(sizeof(node));
    char * c = (char *) malloc(sizeof(char) * 5);

    if(temp)
    {
        linklist -> next = temp -> next;
        strcpy(c, temp->data);
        free(temp);
        return c;
    }

    return "No node";
}

void deleteMiddle(node *linklist, char *item1)
{
    scanf("Enter name to delete: %s", item1);
    node *temp = linklist -> next, *prev = linklist;

    while(temp)
    {
        if (!strcmp(item1, temp -> data))
        {
            prev -> next = temp -> next;
            free(temp);
            return;
        }
        temp = temp -> next;
        prev = prev -> next;
    }
}

char * deleteLast(node *linklist)
{
    node *temp = linklist->next, *prev = linklist;

    if(!temp) 
        return "No node";

    char * c = (char *) malloc(sizeof(char) * 5);

    while(temp->next)
    {
        temp = temp->next;
        prev = prev->next;
    }

    strcpy(c, temp->data);
    prev->next = NULL;
    free(temp);
    return c;
}

void printLinkedList(node *linklist)
{
    node *temp = linklist;

    while(temp -> next)
    {
        temp = temp -> next;
        printf("%s", temp -> data);
        if(temp -> next) 
            printf("->");
    }

    printf("\n");
}

int search(node *linklist, char *item1)
{
    scanf("Enter item to search: %s", item1);
    node *temp = linklist->next;

    while(temp)
    {
        if(!strcmp(item1,temp->data)) 
            return 1;
        temp = temp->next;
    }

    return 0;
}

int length(node *linklist)
{
    int size = 0;
    node *temp = linklist->next;

    while(temp)
    {
        size ++;
        printf("%s", temp->data);
        temp = temp->next;
    }

    return size;
}

char *getData(node *LinkedList)
{
    return LinkedList->data;
}

//node *linklist;
//char *item,*item2