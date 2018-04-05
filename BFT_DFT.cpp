#include <iostream>
#include "intqueue.h"
using namespace std;

const int N=10;

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

void bft(int G[N][N], int v[], queue q, int n)
{
	cout<<peek(q)<<" ";
	v[peek(q)] = 1;
	while(!isemptyq(q))
	{
		int tmp = dequeue(&q);
		//Print all the adjacent vertices
		for(int i=1; i<=n; i++)
		{
			if(G[tmp][i]!=0&&v[i]==0)
			{
				cout<<i<<" ";
			}
		}
		//Enqueue all adjacent vertices
		for(int i=1; i<=n; i++)
		{
			if(G[tmp][i]!=0&&v[i]==0)
			{
				enqueue(&q, i);
				v[i] = 1;
			}
		}
	}
}

void dft(int G[N][N], int v[], int s, int n)
{
	cout<<s<<" ";
	for(int i=1; i<=n; i++)
	{
		if(G[s][i]!=0&&v[i]==0)
		{
			v[i] = 1;
			dft(G, v, i, n);
		}
	}
}

int main()
{
	int G[N][N], v[20], n, s;
	struct queue q;
	//Initialize queue and visited
	q.f = -1; q.r = -1; q.size = 20;
	for(int i=0; i<20; i++)
	{
		v[i] = 0;
	}
	cout<<"Enter size of graph: "; cin>>n;
	createGraph(G, n);
	printMatrix(G, n);
	cout<<"Start with which element?"; cin>>s;
	enqueue(&q, s);
	cout<<"BFT: ";
	bft(G, v, q, n);
	//Reinitialize for DFT
	for(int i=0; i<20; i++)
	{
		v[i] = 0;
	}
	cout<<"\nDFT: ";
	v[s] = 1;
	dft(G, v, s, n);
	return 0;
}
