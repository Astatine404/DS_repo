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

void cpyGraph(int G[N][N], int C[N][N], int n)
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		C[i][j] = G[i][j];
	}
}

void cpyArr(int a[], int c[], int n)
{
	for(int i=1; i<=n; i++)
	c[i] = a[i];
}

void cpyqueue(queue q, queue *c)
{
	c->f = q.f; c->r = q.r; c->size = q.size;
	if(q.f<=q.r)
	{
		for(int i=q.f; i<=q.r; i++)
		c->elements[i] = q.elements[i];
	}
	else
	{
		for(int i=q.f; i<q.size; i++)
		c->elements[i] = q.elements[i];
		for(int i=0; i<=q.r; i++)
		c->elements[i] = q.elements[i];
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

int queue2arr(queue q, int a[])
{
	int i=0;
	while(!isemptyq(q))
	{
		a[i] = dequeue(&q);
		i++;
	}
	return i;
}

int complete(queue q, int n)
{
	int cnt=0;
	while(!isemptyq(q))
	{
		dequeue(&q);
		cnt++;
	}
	if(cnt==n)
	return 1;
	else
	return 0;
}

void sortMain(int G[N][N], queue q, queue final[], int *currfinal, int n, int visited[], int choice)
{
	int tmp, curr, size, C[N][N], tmpvisited[20];
	//Rotate queue till choice at top
	while(true)
	{
		if(peek(q)==choice)
		break;
		tmp = dequeue(&q);
		enqueue(&q, tmp);
	}
	
	//Print dequeued and delete all adjacent edges
	curr = dequeue(&q);
	enqueue(&final[*currfinal], curr);
	for(int i=1; i<=n; i++)
	{
		if(G[curr][i]==1)
		G[curr][i]=0;
	}
	visited[curr] = 1;
	
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
	goto skip;
	//printq(q);
	int a[20];
	size = queue2arr(q, a);
	//printq(q);
	tmp = *currfinal;
	for(int i=0; i<size; i++)
	{
		*currfinal = *currfinal + 1;
		cpyqueue(final[tmp], &final[*currfinal]);
		cpyGraph(G, C, n);
		for(int j=0; j<20; j++)
		tmpvisited[j] = visited[j];
		sortMain(C, q, final, currfinal, n, tmpvisited, a[i]);
	}
	skip:
		{
		}
}

//Helper for sort
void sort(int G[N][N], int n)
{
	int tmp, currfinal=0, visited[20];
	int C[N][N];
	struct queue q, c, final[500];
	//initialize queue
	q.f = -1; q.r = -1; q.size = 50;
	final[0].f = -1; final[0].r = -1; final[0].size = 20;
	
	for(int i=1; i<=n; i++)
	{
		int trig = 0;
		for(int j=1; j<=n; j++)
		{
			if(G[j][i]==1)
			trig = 1;
		}
		if(trig == 0)
		{
			enqueue(&q, i);
		}
	}
	cpyqueue(q, &c);
	while(!isemptyq(c))
	{
		currfinal = 0;
		for(int i=0; i<20; i++)
		{
			visited[i] = 0;
		}
		cpyGraph(G, C, n);
		for(int i=0; i<500; i++)
		{
			final[i].f=-1; final[i].r = -1; final[i].size = 20;
		}
		sortMain(C, q, final, &currfinal, n, visited, dequeue(&c));
		for(int i=0; i<currfinal; i++)
		{
			//if(complete(final[i], n))
			{
				while(!isemptyq(final[i]))
				cout<<dequeue(&final[i])<<" ";
				cout<<endl;
			}
		}
	}
}

int main()
{
	int G[N][N], n;
	cout<<"Enter size of graph: "; cin>>n;
	createGraph(G, n);
	printMatrix(G, n);
	sort(G, n);
	return 0;
}
