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

void printMatrix(int G[N][N], int n)
{
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		cout<<G[i][j]<<" ";
		cout<<endl;
	}
}

void initSet(int S[])
{
	for(int i=1; i<10; i++)
	S[i] = i;
}

void add(int S[], int i, int j)
{
	int tmp = S[i];
	for(int k=1; k<=10; k++)
	{
		if(S[k]==tmp)
		S[k] = S[j];
	}
}


int check(int S[], int i, int j)
{
	if(S[i]==S[j])
	return 1;
	else
	return 0;
}

int main()
{
	int S[10], G[N][N], C[N][N], mini, minj, minl=999, n;
	initSet(S);
	cout<<"Enter size of graph: "; cin>>n;
	createGraph(G, n);
	printMatrix(G, n);
	
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		C[i][j] = 0;
	}
	
	while(true)
	{
		//Find min weight edge in G
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=n; j++)
			{
				if(G[i][j]<minl&&G[i][j]!=0)
				{
					mini = i;
					minj = j;
					minl = G[i][j];
				}
			}
		}
		if(minl==999)
		break;
		//Add to C
		if(!check(S, mini, minj))
		{
			C[mini][minj] = minl;
			C[minj][mini] = minl;
			add(S, mini, minj);
		}
		//Delete from G
		G[mini][minj] = 1000;
		G[minj][mini] = 1000;
		minl = 999;
	}
	cout<<endl<<endl;
	printMatrix(C, n);
	
}
