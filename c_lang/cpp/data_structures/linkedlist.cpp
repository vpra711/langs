#include <iostream>
class node
{
    public:
        int data;
        node *previous;
        node *next;
};

node *newnode()
{
    node *temp = new node();
    temp->next = temp->previous = NULL;
    std::cout << "Enter the value : " << std::endl;
    std::cin >> temp->data;
    return temp;
}

void begin(node *n)
{
    node *temp = newnode();
    temp->next = n;
    n = temp;
    temp->next->previous = temp;
}

void printlist(node *n)
{
    if(n == NULL)
        std::cout << "The list is empty" << std::endl;
    else
    {
        while(n->next != NULL)
        {
            std::cout << n->data;
            n = n->next;
        }
        std::cout << n->data;
        std::cout << std::endl;
        while(n != NULL)
        {
            std::cout << n->data;
            n = n->previous;
        }
    }
}

int main()
{
    node *head = newnode();
    begin(head);
    begin(head);
    begin(head);
    begin(head);
    begin(head);
    printlist(head);
    return 0;
}