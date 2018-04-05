#include <iostream>
#include "intqueue.h"
using namespace std;

const int N=10;

void createGraph(int G[N][N], int n)
{
	cout<<"Enter values in matrix rowwise:";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		cin>>G[i][j];
	}
}

int isunique(int path[], int pathlen)
{
	int trig = 0;
	for(int i=0; i<pathlen; i++)
	{
		for(int j=i+1; j<pathlen; j++)
		{
			if(path[i]==path[j])
			{
				trig = 1;
			}
		}
	}
	if(trig==0)
	return 1;
	else
	return 0;
}


void cycle(int G[N][N], queue q[], int path[], int pathlen, int init, int prev, int curr, int n, int tag, int *qno)
{
	if(curr==init&&tag==1)
	{
		//Print path after checking uniqueness
		if(isunique(path, pathlen))
		{
			//path[pathlen] = curr;
			for(int i=0; i<pathlen; i++)
			enqueue(&q[*qno], path[i]);
			(*qno)++;
		}
	}
	else
	{
		for(int i=0; i<n; i++)
		{
			if(i!=prev)
			{
				if(G[curr][i]==1)
				{
					path[pathlen] = curr;
					cycle(G, q, path, pathlen+1, init, curr, i, n, 1, qno);
				}
			}
		}
	}
	
}

int main()
{
	int G[N][N], n, path[20], qno=0; struct queue q[20];
	//Initialize queue
	for(int i=0; i<20; i++)
	{
		q[i].f=-1; q[i].r=-1; q[i].size=20;
	}
	cout<<"No. of vertices in graph?"; cin>>n;
	createGraph(G, n);
	//for(int i=0; i<n; i++)
	//{
		cycle(G, q, path, 0, 2, 2, 2, n, 0, &qno);
	//}
	
	//Copy queues to arrays
	int a[20][20], size[20];
	for(int i=0; i<20; i++)
	size[i] = 0;
	
	for(int i=0; i<qno; i++)
	{
		while(!isemptyq(q[i]))
		{
			a[i][size[i]] = dequeue(&q[i]);
			size[i]++;
		}
	}
	
	for(int i=0; i<qno; i++)
	{
		for(int j=0; j<size[i]; j++)
		cout<<a[i][j]<<" ";
		cout<<endl;
	}
	
	//Find common element in arrays
	for(int i=0; i<qno; i++)
}
