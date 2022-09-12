#include <iostream>
#include <Windows.h>
typedef struct node node;
struct node 
{
    int data;
    node* next;
    node* previous;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->previous = NULL;
    }
};

 

int main()
{
    node bst = NULL;
    MSG msg;
    //if you add WS_CHILD flag,CreateWindow will fail because there is no parent window.
    HWND hWnd = CreateWindow(TEXT("button"), TEXT("Easy"), WS_VISIBLE | WS_POPUP,
        10, 10, 80, 25, NULL, NULL, NULL,  NULL);

    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}