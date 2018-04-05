#include <iostream>
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


void cycle(int G[N][N], int path[], int pathlen, int init, int prev, int curr, int n, int tag)
{
	if(curr==init&&tag==1)
	{
		//Print Path after checking uniqueness
		if(isunique(path, pathlen))
		{
			path[pathlen] = curr;
			for(int i=0; i<=pathlen; i++)
			cout<<path[i]<<" ";
			cout<<endl;
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
					cycle(G, path, pathlen+1, init, curr, i, n, 1);
				}
			}
		}
	}
	
}

void emptyarr(int a[])
{
	for(int i=0; i<20; i++)
	a[i] = 0;
}

int main()
{
	int G[N][N], n, path[20], i=0;
	cout<<"No. of vertices in graph?"; cin>>n;
	createGraph(G, n);
	//for(int i=0; i<n; i++)
	{
		cout<<endl;
		cycle(G, path, 0, 4, 4, 4, n, 0);
		emptyarr(path);
	}
}
