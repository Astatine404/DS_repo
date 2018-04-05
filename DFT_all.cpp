#include <iostream>
using namespace std;

const int N=10;

void swap(int *p, int *q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
}


}void createGraph(int G[N][N], int n)
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

void printMatrix(int G[N][N], int n)
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		cout<<G[i][j]<<" ";
		cout<<endl;
	}
}

void dft(int G[N][N], int path[], int visited[], int pathlen, int s, int n)
{
	if(pathlen==n)
	{
		//Print path
		for(int i=0; i<pathlen; i++)
		cout<<path[i]<<" ";
		cout<<endl;
	}
	else
	{
		visited[s] = 1;
		for(int i=1; i<=n; i++)
		{
			if(G[s][i]>0&&visited[i]==0)
			{
				path[pathlen] = i;
				dft(G, path, visited, pathlen+1, i, n);
				visited[i] = 0;
			}
		}
	}
}

int main()
{
	int G[N][N], visited[20], path[20], n, s;
	for(int i=0; i<20; i++)
	{
		visited[i] = 0;
	}
	cout<<"Enter size of graph: "; cin>>n;
	createGraph(G, n);
	printMatrix(G, n);
	cout<<"Start with which element?"; cin>>s;
	path[0] = s;
	dft(G, path, visited, 1, s, n);
}
