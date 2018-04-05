#include<iostream>
using namespace std;

const int N=10;

typedef struct vnode
{
	int vno;
	int dist;
	int prev;
	int visited;
} vert;

void swap(vert *p, vert *q)
{
	vert tmp = *p;
	*p = *q;
	*q = tmp;
}

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

int allvisited(vert v[], int n)
{
	int trig=1;
	for(int i=1; i<=n; i++)
	{
		if(v[i].visited==0)
		trig = 0;
	}
	return trig;
}

void heapadd(vert H[], int *s, vert k)
{
	*s = *s + 1;
	H[*s]=k;
	int pos = *s;
	while(pos!=1)
	{
		if(H[pos].dist<H[pos/2].dist)
		swap(&H[pos], &H[pos/2]);
		pos = pos/2;
	}
}

int isPresentinHeap(vert H[], vert k, int s)
{
	int trig = 0;
	for(int i=0; i<=s; i++)
	{
		if(H[i].vno==k.vno)
		trig = 1;
	}
	return trig;
}

void traverse(int G[N][N], vert v[], int s, int d, int n)
{
	int sum; //cout<<"here!";
	v[s].dist = 0;
	vert H[20];
	while(!allvisited(v, n))
	{
		//Find unvisited vertex with least stored dist 
		int min=999, minvert=-1, s=0;
		for(int i=1; i<=n; i++)
		{
			if(v[i].visited==0)
			{
				if(!isPresentinHeap(H, v[i], s))
				heapadd(H, &s, v[i]);
			}
		}
		min = H[1].dist;
		minvert = H[1].vno;
		if(min==999)
		break;
		
		//Assign all adjacent vertices of found vertex
		for(int i=1; i<=n; i++)
		{
			if(G[minvert][i]>0)
			{
				if(v[i].visited==0)
				{
					sum = v[minvert].dist + G[minvert][i];
					if(sum<v[i].dist)
					{
						v[i].dist = sum;
						v[i].prev = minvert;
					}
				}
			}
		}
		v[minvert].visited = 1;
	}
}

void backtrack(vert v[], int d, int s)
{
	if(d!=s)
	{
		cout<<d<<" ";
		backtrack(v, v[d].prev, s);
	}
	else
	cout<<d<<" ";
}

int main()
{
	int G[N][N], s, d, n;
	vert v[20];
	//Initialize vertex data
	for(int i=0; i<20; i++)
	{
		v[i].vno = 0;
		v[i].dist = 999;
		v[i].prev = 0;
		v[i].visited = 0;
	}
	cout<<"Enter size of graph: "; cin>>n;
	createGraph(G, n);
	printMatrix(G, n);
	cout<<"Enter source:"; cin>>s;
	cout<<"Enter destination: "; cin>>d;
	for(int i=1; i<=n; i++)
	{
		v[i].vno = i;
	}
	traverse(G, v, s, d, n);
	cout<<"Path length: "<<v[d].dist<<endl;
	backtrack(v, d, s);
	return 0;
}




