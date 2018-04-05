#include<iostream>
using namespace std;

const int N=20;

typedef struct vnode
{
	int num;
	int low;
	int visited;
	int parent;
} vtype;

void createGraph(int G[N][N], int n)
{
	int a, b, wt;
	//Initialize graph
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		G[i][j] = 0;
	}
	cout<<"Enter pair";
	while(true)
	{
		cin>>a;
		if(a==99)
		break;
		cin>>b;
		G[a][b] = 1;
		G[b][a] = 1;
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

void num_dft(int G[N][N], vtype v[], int vis[], int s, int prev, int n)
{
	static int cnt = 0;
	cnt++;
	v[s].num = cnt;
	v[s].low = cnt;
	vis[s] = 1;
	v[s].parent = prev;
	cout<<s<<" "<<v[s].num<<" "<<v[s].parent<<" "<<endl;
	for(int i=1; i<=n; i++)
	{
		if(G[s][i]!=0)
		{
			if(vis[i]==0)
			{
				vis[i] = 1;
				num_dft(G, v, vis, i, s, n);
			}
			else
			{
				//Backedge
				if(v[s].low>v[i].num&&i!=v[s].parent)
				{
					cout<<"Backedge found from "<<s<<"to "<<i<<endl;
					v[s].low = v[i].num;
				}
			}
		}
	}
}

void tree(vtype v[], int n)
{
	for(int i=1; i<=n; i++)
	{
		if(v[v[i].parent].low>v[i].low)
		{
			cout<<"Change of low for "<<v[i].parent<<" due to tree"<<endl;
			v[v[i].parent].low = v[i].low;
		}
	}
}

int isart(vtype v[], int k, int s)
{
	if(v[i].low>=v[v[i].parent].num&&v[i].parent!=s)
	return 1;
	else
	return 0;
}

int main()
{
	int G[N][N], vis[20], n, s, prev=1;
	vtype v[20];
	for(int i=0; i<20; i++)
	{
		v[i].low = 999;
		v[i].num = 0;
		v[i].parent = 0;
		v[i].visited = 0;
	}
	
	for(int i=0; i<20; i++)
	{
		vis[i] = 0;
	}
	cout<<"Enter size of graph: "; cin>>n;
	createGraph(G, n);
	printMatrix(G, n);
	cout<<"Start with which element?"; cin>>s;
	num_dft(G, v, vis, s, prev, n);
	tree(v, n);
	//Print all lows
	for(int i=1; i<=n; i++)
	{
		cout<<i<<" "<<v[i].low<<endl;
	}
	//Check articulation point condition
	cout<<"Articulation points: \n";
	for(int i=1; i<=n; i++)
	{
		if(v[i].low>=v[v[i].parent].num&&v[i].parent!=s)
		cout<<v[i].parent<<" ";
	}
	//Biconnected components
	return 0;
}
