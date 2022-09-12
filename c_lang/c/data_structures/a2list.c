#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"

void Reverse(node *ll)
{
    node *curr = ll->next;
    node *prev = NULL, *after = NULL;

    while (curr)
    {
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }

    ll->next = prev;
}

void createSorted(node *ll, char * item)
{
    char after[5];
    node *curr = ll->next;

    if (strcmp(curr->data, item)>0)
    {
        insertFirst(ll, item);
        return;
    }

    while (curr->next)
    {
        strcpy(after, curr->data);
        if (strcmp(curr->data, item) < 0 && strcmp(curr->data, item) > 0)
        {
            insertMiddle(ll, after, item);
            return;
        }
        curr = curr->next;
    }

    strcpy(after, curr->data);
    insertMiddle(ll, after, item);
}

void rotateLeft(node *ll)
{
    char addtoend[5];
    strcpy(addtoend, getData(ll));
    insertLast(ll, addtoend);
    deleteFirst(ll);
}



int main()
{
    char item1[5];
    char item2[5];
    node *head = (node *) malloc(sizeof(node));
    node *revhead = (node *) malloc(sizeof(node));
    revhead->next = NULL;
    head -> next = NULL;
    int choice = 1;
    printf(" ---------MENU---------\n0.Exit\n1.InsertFirst\n2.InsertMiddle\n3.InsertLast\n4.DeleteFirst\n5.DeleteMiddle"
    "\n6.DeleteLast\n7.Search\n8.Print the list\n9.Length of the list\n10.Get Data\n11.Reverse"
    "\n12.CreateSorted\n13.Rotate Left\n\n");

    do
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1 :printf("Enter item: ");
                    scanf("%s", item1);
                    insertFirst(head, item1);
                    break;
            case 2 :printf("Enter item1: ");
                    scanf("%s", item1);
                    printf("Enter item2: ");
                    scanf("%s", item2);
                    insertMiddle(head, item1, item2);
                    break;
            case 3 :printf("Enter item: ");
                    scanf("%s", item1);
                    insertLast(head, item1);
                    break;
            case 4 :printf("Deleted %s\n", deleteFirst(head));
                    break;
            case 5 :printf("Enter name to delete: ");
                    scanf("%s", item1);
                    deleteMiddle(head, item1);
                    break;
            case 6 :printf("Deleted %s\n", deleteLast(head));
                    break;
            case 7 :printf("Enter item to search: ");
                    scanf("%s", item1);
                    if (search(head, item1) == 1) 
                        printf("Element found!\n");
                    else
                        printf("Element not found!\n");
                    break;
            case 8 :printLinkedList(head);
                    break;
            case 9 :printf("The length of the linked list is %d\n", length(head));
                    break;
            case 10:printf("Data in the node pointed by the pointer to link list:%s\n",getData(head));
                    break;
            case 11:Reverse(head);
                    break;
            case 12:printf("Enter item to enter in lexical order: ");
                    scanf("%s", item1);
                    createSorted(head, item1);
                    break;
            case 13:rotateLeft(head);
                    printLinkedList(head);
                    break;
            case 0 :printf("Exiting the program.\n");
                    break;
            default:
                    printf("Wrong option, try again\n");
        }
    }while(choice != 0);
}