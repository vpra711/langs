#include <stdio.h>

struct process 
{
	int AT, BT, WT, TAT;
    char pid[10];
}a[10];

int queue[100];
int front = -1;
int rear = -1;

void insert(int n) 
{
	if (front == -1)
		front = 0;
	rear = rear + 1;
	queue[rear] = n;
}

int delete() 
{
	int n;
	n = queue[front];
	front = front + 1;
	return n;
}

int main() 
{
	int n, TQ, p, TIME = 0;
	int temp[10], exist[10] = {0};
	float total_wt = 0, total_tat = 0, Avg_WT, Avg_TAT;
	printf("Enter the number of the process: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++) 
    {
        printf("Enter the process ID: ");
        scanf("%s", &a[i].pid);
        printf("Enter the Arrival time: ");
	    scanf("%d", &a[i].AT);
        printf("Enter the Burst Time: ");
        scanf("%d", &a[i].BT);
	    temp[i] = a[i].BT;
	}

	printf("Enter the time quantum: ");
	scanf("%d", &TQ);
	insert(0);
	exist[0] = 1;

    printf("\nGantt Chart : 0");
    int bursttime = 0;
	while (front <= rear) 
    {
		p = delete();

		if (a[p].BT >= TQ) 
        {
			bursttime = TQ;
			a[p].BT = a[p].BT - TQ;
			TIME = TIME + TQ;
		} 
        else 
        {
			bursttime = a[p].BT;
			TIME = TIME + a[p].BT;
			a[p].BT = 0;
		}

		for (int i = 0; i < n; i++) 
        {
			if (exist[i] == 0 && a[i].AT <= TIME) 
            {
				insert(i);
				exist[i] = 1;
			}
		}

		if (a[p].BT == 0) 
        {
			a[p].TAT = TIME - a[p].AT;
			a[p].WT = a[p].TAT - temp[p];
			total_tat = total_tat + a[p].TAT;
			total_wt = total_wt + a[p].WT;
		} 
        else 
        {
			insert(p);
		}
        printf(" -> [%s, %d] -> %d", a[p].pid, bursttime, TIME);
	}    

	Avg_TAT = total_tat / n;
	Avg_WT = total_wt / n;

    printf("\n\n-----------------------------------\n");
	printf("ID\tAT\tBT\tWT\tTAT\n");
    printf("-----------------------------------\n");

	for (int i = 0; i < n; i++) 
		printf("%s\t%d\t%d\t%d\t%d\n", a[i].pid, a[i].AT, a[i].BT, a[i].WT, a[i].TAT);

	printf("Average waiting time of the processes is : %f\n", Avg_WT);
	printf("Average turn around time of the processes is : %f\n", Avg_TAT);
	return 0;
}