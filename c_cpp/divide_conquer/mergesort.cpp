#include <iostream>

void mergesort(int *, int, int);
void merge(int *, int, int, int);

int main()
{
    int A[] = {9, 8, 7, 6, 5, 4, 3, 2, 1}, aSize = sizeof(A)/sizeof(A[0])-1;
    mergesort(A, 0, aSize);

    for(int i = 0; i <= aSize; i++)
        std::cout << A[i] << "\n";

    return 0;
}

void mergesort(int *A, int begin, int end)
{
    if(begin < end)
    {     
        int mid = ( begin + end ) / 2;
        mergesort(A,begin,mid);
        mergesort(A,mid+1,end);
        merge(A,begin,mid,end);
    }
}

void merge(int *A, int begin, int mid, int end)
{
    int n1 = mid-begin+1, n2 = end-mid, i, j, k;
    int *Left = (int *) calloc(n1, sizeof(int)), *Right = (int *) calloc(n2, sizeof(int));

    for(i = 0; i < n1; i++)
        Left[i] = A[begin+i];

    for(j = 0; j < n2; j++)
        Right[j] = A[mid+j+1];

    i = j = 0;
    k = begin;

    while(i < n1 && j < n2)
        if(Left[i] <= Right[j])
            A[k++] = Left[i++];
        else
            A[k++] = Right[j++];

    while(i < n1)
        A[k++] = Left[i++];
    
    while(j < n2)
        A[k++] = Right[j++];
}