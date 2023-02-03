#include <iostream>

class Node
{
    public:
        int data;
        Node* next;

    Node()
    {
        data = 0;
        next = NULL;
    }

    Node(int value)
    {
        data = value;
        next = NULL;
    }

    void insert(int data)
    {
        Node* temp = this;   

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = new Node(data);
    }
};

Node* swap(Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    
    Node* second = head->next;
    head->next = second->next;
    second->next = head;
    head->next = swap(head->next);
    head = second;

    return head;
}

void print(Node* head)
{
    while(head != NULL)
    {
        std::cout << head->data << "\t";
        head = head->next;
    }

    std::cout << std::endl;
}

int main()
{
    Node* ll = new Node(1);
    ll->insert(2);
    ll->insert(3);
    ll->insert(4);
    ll->insert(5);

    print(ll);
    ll = swap(ll);
    print(ll);

    std::cout << "paused";
    system("pause>0");

    return 0;
}