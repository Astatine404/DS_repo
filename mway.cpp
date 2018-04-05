#include <iostream>
using namespace std;

typedef struct mtnode
{
	int cnt;
	int data[100];
	struct mtnode *child[101];
} mtptr;

void swap(int *p, int *q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
}

void minorder(mtptr *T, int m)
{
	if(T!=NULL)
	{
		for(int i=0; i<=T->cnt; i++)
		{
			minorder(T->child[i], m);
			cout<<T->data[i];
			if(i==T->cnt)
			minorder(T->child[i+1], m);
		}
	}
}

mtptr *newNode(int dat, int m)
{
	mtptr *T;
	T = new(mtnode);
	T->data[0] = dat;
	T->cnt = 0;
	for(int i=0; i<m; i++)
	T->child[i] = NULL;
	return T;
}

void create(mtptr **T, int m, int dat)
{
	if((*T)==NULL)
	{
		(*T) = newNode(dat, m);
	}
	else
	{
		for(int i=0; i<=(*T)->cnt; i++)
		{
			if(i==0)
			{
				if(dat<(*T)->data[i])
				{
					create(&(*T)->child[i], m, dat);
					break;
				}
				else if(dat>(*T)->data[i])
				{
					create(&(*T)->child[i+1], m, dat);
					break;
				}
				
			}
			if(i!=(*T)->cnt&&i!=0)
			{
				if(dat>(*T)->data[i-1]&&dat<(*T)->data[i])
				{
					create(&(*T)->child[i], m, dat);
					break;
				}
			}
			if(i==(*T)->cnt)
			{
				if((*T)->cnt!=m-2)
				{
					(*T)->cnt = (*T)->cnt + 1;
					(*T)->data[(*T)->cnt] = dat;
				}
				else
				create(&(*T)->child[(*T)->cnt+1], m, dat);
			}
			
		}
	}
}

int main()
{
	mtptr *T; int t; T = NULL;
	while(true)
	{
		cin>>t;
		if(t==99)
		break;
		create(&T, 3, t);
		minorder(T, 3); cout<<endl;
	}
	
}
