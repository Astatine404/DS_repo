#include<iostream>
using namespace std;

const int N=10;

struct gnode
{
	int wt;
	int u;
	int v;
};

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

int present(gnode v[], int vlen, int u, int k)
{
	int trig = 0;
	for(int i=0; i<vlen; i++)
	{
		if(v[i].v==k&&v[i].u==u)
		{
			trig = 1;
			break;
		}
	}
	return trig;
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

int presentinset(int visited[], int setlen, int k)
{
	int trig = 0;
	for(int i=0; i<setlen; i++)
	{
		if(visited[i]==k)
		{
			trig = 1;
			break;
		}
	}
	return trig;
}

int getsize(int C[N][N], int n)
{
	int deg = 0, k=n;
	for(int i=1; i<=n; i++)
	{
		deg = 0;
		for(int j=1; j<=n; j++)
		{
			if(C[i][j]>0)
			deg++;
		}
		if(deg==0)
		k--;
	}
	return k;
}

int main()
{
	int G[N][N], C[N][N], maxe, maxi, maxj, maxl=-1, n, trig=0, visited[40], vlen=0, setlen=0, csize=0;
	struct gnode v[40];
	cout<<"Enter size of graph: "; cin>>n;
	createGraph(G, n);
	printMatrix(G, n);
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		C[i][j] = 0;
	}
	for(int i=0; i<40; i++)
	visited[i] = 0;
	
	for(int i=1; i<=n; i++)
	{
		//Check adjacent
		for(int j=1; j<=n; j++)
		{
			if(G[i][j]>0&&!present(v, vlen, i, j))
			{
				C[i][j] = G[i][j];
				v[vlen].u = i; v[vlen].v = j; v[vlen].wt = G[i][j];
				vlen++;
			}
		}
		setlen = 0; maxl=-1;
		while(true)
		{
			maxl = -1;
			//Try removing max edge present and check for disconnection
			for(int j=0; j<vlen; j++)
			{
				if(v[j].wt>maxl&&!presentinset(visited, setlen, j))
				{
					maxe = j;
					maxl = v[j].wt;
				}
			}
			if(maxl==-1)
			break;
			maxi = v[maxe].u;
			maxj = v[maxe].v;
			C[maxi][maxj] = 0;
			C[maxj][maxi] = 0;
			if(!isconnected(C, n))
			{
				C[maxi][maxj] = maxl;
				C[maxj][maxi] = maxl;
			}
			visited[setlen] = maxe;
			setlen++;
		}
	}
	cout<<endl<<endl;
	printMatrix(C, n);
	return 0;
	
}
