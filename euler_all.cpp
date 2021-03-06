#include<iostream>
using namespace std;

const int N=30;
void eulerHelper(int[N][N], int*, int*, int, int);

void createGraph(int G[N][N], int n)
{
	int a, b;
	//Initialize graph
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		G[i][j] = 0;
	}
	cout<<"Enter pair ";
	while(true)
	{
		cin>>a;
		if(a==99)
		break;
		cin>>b;
		G[a][b] = 1;
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

void cpyArr(int a[], int c[], int n)
{
	for(int i=0; i<n; i++)
	c[i] = a[i];
}

int degree(int G[N][N], int v, int n)
{
	int cnt = 0;
	for(int i=1; i<=n; i++)
	{
		if(G[v][i]>0)
		cnt++;
	}
	return cnt;
}

int completed(int G[N][N], int n)
{
	int trig = 1;
	for(int i=1; i<=n; i++)
	{
		if(degree(G, i, n)!=0)
		trig = 0;	
	}
	return trig;
}

void euler(int G[N][N], int path[], int *pathlen, int n)
{
	int next, pos;
	
	recheck:
	if(!completed(G, n))
	{
		//Find the element in path which has non-zero degree
		for(int i=0; i<(*pathlen); i++)
		{
			if(degree(G, path[i], n)!=0)
			{
				next = path[i];
				pos = i;
				break;
			}
		}
		//Find new path from next
		int splicePath[50], splicelen=1;
		splicePath[0] = next;
		eulerHelper(G, splicePath, &splicelen, next, n);
		//Merge splicePath with path
		int cpy[50], j = 0;
		for(int i=pos+1; i<(*pathlen); i++)
		{
			cpy[j] = path[i];
			j++;
		}
		int cpos = pos;
		for(int i=0; i<splicelen; i++)
		{
			path[cpos] = splicePath[i];
			cpos++;
		}
		//Append cpy to path
		for(int i=0; i<j; i++)
		{
			path[cpos] = cpy[i];
			cpos++;
		}
		*pathlen = cpos;
		goto recheck;
	}
}

void eulerHelper(int G[N][N], int path[], int *pathlen, int s, int n)
{
	int C[N][N], tmppathlen, c[50]; 
	iter:
	for(int i=1; i<=n; i++)
	{
		if(G[s][i]==1)
		{
			path[*pathlen] = i;
			*pathlen = *pathlen + 1;
			G[s][i] = 0;
			G[i][s] = 0;
			cpyGraph(G, C, n);
			cpyArr(path, c, *pathlen);
			tmppathlen = *pathlen;
			eulerHelper(G, c, &tmppathlen, i, n);
		}
	}
	euler(G, path, pathlen, n);
	for(int i=0; i<*pathlen; i++)
	cout<<path[i]<<" ";
	cout<<endl;
}

int main()
{
	int G[N][N], n, path[50], pathlen=1, s;
	cout<<"Enter size of graph: "; cin>>n;
	createGraph(G, n);
	printMatrix(G, n);
	cout<<"Where to start?"; cin>>s;
	path[0] = s;
	eulerHelper(G, path, &pathlen, s, n);
	//Print path
}
