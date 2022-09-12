#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void merge(int [],int ,int );
void mergesort(int [],int ,int , int );

void main()
{
    int A[] = {2,4,5,7,1,2,3,6};
    merge(A,1,8);
    for(int i = 0;i < 8 ;i++)
        printf("%d\n",A[i]);
}

void merge(int A[],int p,int r)
{
    if(p < r)
    {      
        int q = (p+r) / 2;
        merge(A,p,q);
        merge(A,q+1,r);
        mergesort(A,p,q,r);
    }
}

void mergesort(int A[],int p,int q,int r)
{
    int n1 = q-p+1 , n2 = r-q , i , j , k;
    int *L = calloc(n1,sizeof(int)) ,*R = calloc(n2,sizeof(int));

    for(i = 0 ; i < n1 ; i++)
        L[i] = A[p+i-1];

    for(j = 0 ; j < n2 ; j++)
        R[j] = A[q+j];

    i = j = 0;

    for(k = p-1 ; k < r ; k++)
    {
        if((i != n1) && (j != n2))
            if(L[i] <= R[j])
            {
                A[k] = L[i];
                i++;
            }
            else
            {
                A[k] = R[j];
                j++;
            }
    }

    /*while( i != n1 )
        A[k++] = L[i++];

    while( j != n2 )
        A[k++] = R[j++];*/
            
    printf("%d%d%d%d%d",p,q,r,n1,n2);
    printf("\n---------------------------\n");

    for(i = 0; i < n1 ; i++)
        printf("%d\t",L[i]);

    printf("\n---------------------------\n");

    for(i = 0; i < n2 ; i++)
        printf("%d\t",R[i]);

    printf("\n---------------------------\n");    
    printf("\nstarting of array A\n");

    for(i = 0; i < 8 ; i++)
        printf("%d\t",A[i]);

    printf("\nEnd of array A\n");
    printf("\n---------------------------\n\n\n");
}