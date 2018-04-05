#include<iostream>
using namespace std;
const int N=10;

struct adnode;
typedef struct gnode
{
	int data;
	struct gnode *vnext;
	struct adnode *alist;
} gptr;

typedef struct adnode
{
	struct gnode *av;
	struct adnode *avnext;
} adptr;


void createGraph(int G[N][N], int n)
{
	cout<<"Enter values in matrix rowwise:";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		cin>>G[i][j];
	}
}

void createbase(gptr **T, int n, int i)
{
	if(i<n)
	{
		if((*T)==NULL)
		{
			(*T) = new(gnode);
			(*T)->data = i;
			(*T)->vnext = NULL;
			(*T)->alist = NULL;
			createbase(&(*T)->vnext, n, i+1);
		}
	}
}

void pt2node(gptr *root, adptr *T, int val)
{
	while(root!=NULL)
	{
		if(root->data == val)
		{
			T->av = root;
		}
		root = root->vnext;
	}
}

void insert(gptr *T, int k, int val)
{
	gptr *tmp = T;
	while(T!=NULL)
	{
		if(T->data == k)
		break;
		T = T->vnext;
	}
	if(T->alist==NULL)
	{
		T->alist = new(adnode);
		pt2node(tmp, T->alist, val);
	}
	else
	{
		adptr *L = T->alist;
		while(L->avnext!=NULL)
		L = L->avnext;
		L->avnext = new(adnode);
		pt2node(tmp, L->avnext, val);
	}
}

void convert(int G[N][N], gptr **T, int n)
{
	createbase(T, n, 0);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(G[i][j]==1)
			insert(*T, i, j);
		}
	}
}

int main()
{
	int G[N][N], n;
	cout<<"No. of vertices in graph?"; cin>>n;
	createGraph(G, n);
	gptr *T; T = NULL;
	convert(G, &T, n);
	return 0;
}
