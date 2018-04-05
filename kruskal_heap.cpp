#include<iostream>
using namespace std;

struct gnode
{
	int wt;
	int u;
	int v;
};

void swap(int *p, int *q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
}

int createGraph(gnode G[])
{
	int cnt=0, tmp;
	while(true)
	{
		cin>>tmp;
		if(tmp==99)
		break;
		G[cnt].u = tmp;
		cin>>G[cnt].v>>G[cnt].wt;
		cnt++;
	}
	return cnt;
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


int check(int S[], int i, int j)
{
	if(S[i]==S[j])
	return 1;
	else
	return 0;
}


int main()
{
	int S[10], n;
	struct gnode G[30];
	int minv, minl=999;
	n = createGraph(G);
	initSet(S);
	while(true)
	{
		minl = 999; int H[20], size=0;
		//Find min
		for(int i=0; i<n; i++)
		{
			if(G[i].wt!=999)
			heapadd(H, &size, G[i].wt);
		}
		if(size==0)
		break;
		
		minl = H[1];
		for(int i=0; i<n; i++)
		{
			if(G[i].wt==minl)
			minv = i;
		}		
		//Add to set
		if(!check(S, G[minv].u, G[minv].v))
		{
			add(S, G[minv].u, G[minv].v);
			cout<<G[minv].u<<" "<<G[minv].v<<" "<<G[minv].wt<<endl;
		}
			
		
		//Delete from original
		G[minv].wt = 999;
	}
}
