#include <iostream>
using namespace std;

typedef struct lnode
{
	int data;
	struct lnode *next;
} lptr;

typedef struct ptrbucket {
	lptr *L;
	struct ptrbucket *nextb;
} bptr;

void addend(bptr *B, int k)
{
	if(B->L->data==-1)
	{
		B->L->data=k;
		B->L->next=NULL;
	}
	else
	{
		lptr *T, *S;
		S = B->L;
		while(B->L->next!=NULL)
		B->L=B->L->next;
		T=new(lnode);
		T->data=k;
		T->next=NULL;
		B->L->next=T;
		B->L = S;
	}
}

void addfront(bptr *B, int k)
{
	if(B->L->data==-1)
	{
		B->L->data=k;
		B->L->next=NULL;
	}
	else
	{
		lptr *T;
		T = new(lnode);
		T->data=k;
		T->next=B->L;
		B->L=T;
	}
}

int deletefront(bptr *B)
{
	int val = B->L->data;
	if(B->L->next==NULL)
	B->L->data=-1;
	else
	B->L = B->L->next;
	return val;
}

int main()
{
	int n;
	cout<<"No. of elements: "; cin>>n;
	int a[n], tmp;
	bptr *q[10];
	cout<<"Enter the elements: ";
	for(int i=0; i<n; i++)
	cin>>a[i];
	//Initializing lists
	for(int i=0; i<10; i++)
	{
		q[i] = new(ptrbucket);
		if(i<9)
		q[i]->nextb = q[i+1];
		else if(i==9)
		q[i]->nextb = NULL;
		q[i]->L = new(lptr);
		q[i]->L->data = -1;
	}
	//Sorting
	for(int i=0, radix=1; i<5; i++, radix *= 10)
	{
		for(int m=0; m<n; m++)
		{
			tmp = (a[m]/radix)%10;
			for(int j=0; j<10; j++)
			{
				if(tmp == j)
				addend(q[j], a[m]);
			}
		}
		int p=0;
		for(int m=0; m<10; m++)
		{
			while(q[m]->L->data!=-1)
			{
				tmp = deletefront(q[m]);
				a[p] = tmp;
				p++;
			}
		}
	}
	//Print sorted array
	for(int i=0; i<n; i++)
	cout<<a[i]<<" ";
	return 0;
}
