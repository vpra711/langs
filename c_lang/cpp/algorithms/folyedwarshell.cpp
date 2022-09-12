#include<iostream>

const int V = 5;
const int INF = 99999;

void printSolution(int dist[V][V]);
void floydWarshall (int graph[V][V])
{
	int dist[V][V], i, j, k;
	for (i = 0; i < V; i++)
		for (j = 0; j < V; j++)
			dist[i][j] = graph[i][j];
	for (k = 0; k < V; k++)
	{
		for (i = 0; i < V; i++)
		{
			for (j = 0; j < V; j++)
			{
				if (dist[i][k] + dist[k][j] <= dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
		printSolution(dist);
	}
	printSolution(dist);
}

void printSolution(int dist[V][V])
{
	std::cout<<"The following matrix shows the shortest distances"
			" between every pair of vertices \n";
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			if (dist[i][j] == INF)
				std::cout<<"INF"<<"	";
			else
				std::cout<<dist[i][j]<<"	";
		}
		std::cout<<std::endl;
	}
}

int main()
{
	int graph[V][V] = { 
		                {0, 2, INF, 1 , 8 },
						{6 , 0, 3, 2, INF},
						{INF, INF, 0, 4, INF},
						{INF, INF, 2, 0, 3},
						{ 3, INF, INF, INF, 0}
					  };
	floydWarshall(graph);
	return 0;
}