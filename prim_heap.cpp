#include<iostream>
using namespace std;

const int N=10;

void swap(int *p, int *q)
{
	int tmp = *p;
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
		G[b][a] = wt;
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

int present(int set[], int setlen, int v)
{
	int trig = 0;
	for(int i=0; i<setlen; i++)
	{
		if(set[i]==v)
		{
			trig = 1;
			break;
		}
	}
	return trig;
}

void heapadd(int H[], int *s, int k)
{
	*s = *s + 1;
	H[*s]=k;
	int pos = *s;
	while(pos!=1)
	{
		if(H[pos]<H[pos/2])
		swap(&H[pos], &H[pos/2]);
		pos = pos/2;
	}
	
}

int main()
{
	int S[10], G[N][N], C[N][N], n, s, minv, minl, prev;
	int set[40], setlen=1;
	cout<<"Size of graph? "; cin>>n;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		C[i][j] = 0;
	}
	createGraph(G, n);
	printMatrix(G, n);
	cout<<"Where to start? "; cin>>s;
	set[0] = s;
	while(true)
	{
		minl = 999; int H[20], size=0;
		for(int i=0; i<setlen; i++)
		{
			//Check adjacent vertices
			for(int j=1; j<=n; j++)
			{
				if(G[set[i]][j]>0&&!present(set, setlen, j))
				{
					heapadd(H, &size, G[set[i]][j]);
				}
			}
		}
		if(size==0)
		break;
		minl = H[1]; cout<<minl;
		for(int i=0; i<setlen; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(G[set[i]][j]>0)
				{
					if(G[set[i]][j]==minl&&!present(set, setlen, j))
					{
						prev = set[i];
						minv = j;
					}
				}
			}
		}
		
		//Add edge to C
		C[prev][minv] = minl;
		C[minv][prev] = minl;
		//Add to set
		set[setlen] = minv;
		setlen++;
	}
	cout<<endl<<endl;
	printMatrix(C, n);
}
