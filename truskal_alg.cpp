#include<iostream>
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
		G[b][a] = wt;
	}
}

void dft(int G[N][N], int v[], int s, int n, int *cnt)
{
	*cnt = *cnt + 1;
	for(int i=1; i<=n; i++)
	{
		if(G[s][i]!=0&&v[i]==0)
		{
			v[i] = 1;
			dft(G, v, i, n, cnt);
		}
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

void cpyGraph(int G[N][N], int C[N][N], int n)
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		C[i][j] = G[i][j];
	}
}

int isconnected(int G[N][N], int n)
{
	int v[20], cnt=0;
	for(int i=0; i<20; i++)
	v[i] = 0;
	dft(G, v, 1, n, &cnt);
	if(cnt-1==n)
	return 1;
	else
	return 0;
}

int main()
{
	int S[10], G[N][N], C[N][N], maxi, maxj, maxl=-1, n, trig=0;
	cout<<"Enter size of graph: "; cin>>n;
	createGraph(G, n);
	printMatrix(G, n);
	cpyGraph(G, C, n);
	
	while(true)
	{
		//Find max weight edge in C
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(C[i][j]>maxl)
				{
					maxi = i;
					maxj = j;
					maxl = C[i][j];
				}
			}
		}
		C[maxi][maxj] = 0;
		C[maxj][maxi] = 0;
		if(!isconnected(C, n))
		{
			C[maxi][maxj] = 1;
			C[maxj][maxi] = 1;
		}
		maxl = -1; trig = 0;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(C[i][j]!=0&&C[i][j]!=1)
				trig = 1;
			}
		}
		if(trig==0)
		break;
	}
	
	//Restore backtracked edges
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(C[i][j]==1)
			C[i][j] = G[i][j];
		}
	}
	cout<<endl<<endl;
	printMatrix(C, n);
	
}
