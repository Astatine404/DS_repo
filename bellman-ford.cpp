#include<iostream>
using namespace std;

const int N=10;

typedef struct vnode
{
	int dist;
} vert;

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

void graphInit(vert v[], int s, int n)
{
	for(int i=1; i<=n; i++)
	{
		v[i].dist = 999;
	}
	v[s].dist = 0;
}

void updateDist(int G[N][N], vert v[], int n)
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(G[i][j]!=0)
			{
				if(v[j].dist>v[i].dist + G[i][j])
				v[j].dist = v[i].dist + G[i][j]; 
			}
		}
	}
}

int main()
{
	int G[N][N], s, n;
	vert v[20];
	cout<<"Enter size of graph: "; cin>>n;
	createGraph(G, n);
	printMatrix(G, n);
	cout<<"Enter source:"; cin>>s;
	graphInit(v, s, n);
	for(int i=0; i<n-1; i++)
	{
		cout<<"\nIteration "<<i+1<<endl;
		updateDist(G, v, n);
		//Printing
		for(int i=1; i<=n; i++)
		{
			cout<<"Vertex "<<i<<": "<<v[i].dist<<endl;
		}
	}
	return 0;
}
