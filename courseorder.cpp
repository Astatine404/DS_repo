#include<iostream>
#include "intqueue.h"
using namespace std;

const int N=30;

void createGraph(int G[N][N], int n)
{
	int a, b, wt;
	//Initialize graph
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		G[i][j] = 0;
	}
	cout<<"Enter pair and weight";
	while(true)
	{
		cin>>a;
		if(a==99)
		break;
		cin>>b>>wt;
		G[a][b] = wt;
	}
}

void printMatrix(int G[N][N], int n)
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		cout<<G[i][j]<<" ";
		cout<<endl;
	}
}

void order(int G[N][N], queue q, int n, int visited[])
{
	int choice, tmp;
	while(true)
	{
		//Ensure the queue is empty
		while(!isemptyq(q))
		dequeue(&q);
		//Enqueue all vertices with no indegree and not already visited
		for(int i=1; i<=n; i++)
		{
			int trig = 0;
			for(int j=1; j<=n; j++)
			{
				if(G[j][i]==1)
				trig = 1;
			}
			if(trig == 0&&visited[i]==0)
			{
				enqueue(&q, i);
			}
		}
		if(isemptyq(q))
		break;
		printq(q);
		cout<<"Enter your next choice?";
		cin>>choice;
		//Rotate queue till choice at top
		while(true)
		{
			if(peek(q)==choice)
			break;
			tmp = dequeue(&q);
			enqueue(&q, tmp);
		}
		//Print dequeued and delete all adjacent edges
		int curr = dequeue(&q);
		//cout<<curr<<" ";
		for(int i=1; i<=n; i++)
		{
			if(G[curr][i]==1)
			G[curr][i]=0;
		}
		visited[curr] = 1;
	}
}

int main()
{
	int G[N][N], visited[20], n;
	struct queue q;
	//initialize queue
	q.f = -1; q.r = -1; q.size = 20;
	for(int i=0; i<20; i++)
	{
		visited[i] = 0;
	}
	cout<<"Enter size of graph: "; cin>>n;
	createGraph(G, n);
	printMatrix(G, n);
	order(G, q, n, visited);
	return 0;
}
