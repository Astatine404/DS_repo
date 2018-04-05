#include<iostream>
using namespace std;

const int N=20;

void createGraph(int G[N][N], int n)
{
	int a, b;
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

void dft(int G[N][N], int v[], int pno[], int s, int n, int *curr)
{
	v[s] = 1;
	for(int i=1; i<=n; i++)
	{
		if(G[s][i]!=0&&v[i]==0)
		{
			dft(G, v, pno, i, n, curr);
		}
	}
	if(pno[s]==0)
	{
		*curr = *curr + 1;
		pno[s] = *curr;
	}
}

void dftprint(int G[N][N], int v[], int s, int n)
{
	cout<<s<<" ";
	v[s] = 1;
	for(int i=1; i<=n; i++)
	{
		if(G[s][i]!=0&&v[i]==0)
		{
			dftprint(G, v, i, n);
		}
	}
}

void emptyarr(int v[])
{
	for(int i=0; i<20; i++)
	v[i] = 0;
}

int main()
{
	int G[N][N], s, n, visitdfs[20], visited[20], pno[20], curr=0, next, mpno=0, v;
	cout<<"Enter size of graph: "; cin>>n;
	createGraph(G, n);
	printMatrix(G, n);
	emptyarr(visitdfs); emptyarr(visited); emptyarr(pno);
	cout<<"Start from? "; cin>>s;
	emptyarr(visitdfs);
	repeat:
	dft(G, visitdfs, pno, s, n, &curr);
	//Print pno
	for(int i=1; i<=n; i++)
	cout<<pno[i]<<" ";
	cout<<endl;
	next=0;
	for(int i=1; i<=n; i++)
	{
		if(pno[i]==0)
		{
			next = i;
			break;
		}
	}
	if(next!=0)
	{
		s=next;
		goto repeat;
	}
	//Reverse graph
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			if(G[i][j]==1)
			{
				G[j][i] = 2;
				G[i][j] = 0;
			}
		}
	}
	printMatrix(G, n);
	emptyarr(visited); emptyarr(visitdfs); cout<<endl;
	while(true)
	{
		mpno = -1;
		//Find highest pno
		for(int i=1; i<=n; i++)
		{
			if(pno[i]>mpno&&visited[i]==0)
			{
				v = i;
				mpno = pno[i];
			}
		}
		if(mpno==-1)
		break;
		dftprint(G, visited, v, n);
		cout<<endl;
	}
	return 0;
}
