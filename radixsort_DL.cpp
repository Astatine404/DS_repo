#include<iostream>
using namespace std;

typedef struct lnode
	{
		int data1;
		struct lnode *next;
	} bucket;

typedef struct dlnode
{
	struct dlnode *left;
	int data;
	struct lnode *bptr;
	struct dlnode *right;
} dlptr;

void addbucketend(dlptr *DL, int k)
{
	if(DL->data==-1)
	{
		DL->data = k;
		DL->right = NULL;
		DL->left = NULL;
		bucket *T;
		T = new(lnode);
		T->data1=-1; T->next=NULL;
		DL->bptr= T;
	}
	else
	{
		while(DL->right!=NULL)
		DL = DL->right;
		dlptr *T;
		T = new(dlnode);
		T->data = k;
		T->right = NULL;
		T->left = DL;
		bucket *T1;
		T1 = new(lnode);
		T1->data1 = -1;
		T1->next = NULL;
		T->bptr = T1;
		DL->right = T;
	}
}


int deletefront(dlptr *DL)
{
	int val = DL->bptr->data1;
	if(DL->bptr->next==NULL)
	DL->bptr->data1=-1;
	else
	DL->bptr = DL->bptr->next;
	return val;
}

void addend(dlptr *DL, int k)
{
	if(DL->bptr->data1==-1)
	{
		DL->bptr->data1=k;
		DL->bptr->next=NULL;
	}
	else
	{
		bucket *T;
		bucket *save;
		save = DL->bptr;
		while(DL->bptr->next!=NULL)
		DL->bptr=DL->bptr->next;
		T=new(lnode);
		T->data1=k;
		T->next=NULL;
		DL->bptr->next=T;
		DL->bptr = save;
	}
}

int main()
{
	dlptr *DL[10], *T; int n, tmp;
	
	//Initializing Lists
	for(int i=0; i<10; i++)
	{
		DL[i] = new(dlnode);
		DL[i]->data = -1; DL[i]->right = NULL; DL[i]->left=NULL;
		addbucketend(DL[i], i);
	}
	cout<<"Number of elements?";
	cin>>n;
	
	int a[n];
	cout<<"Enter elements: ";
	for(int i=0; i<n; i++)
	cin>>a[i];
	
	for(int i=0, radix = 1; i<5; i++, radix *= 10)
	{
		for(int m=0; m<n; m++)
		{
			tmp = (a[m]/radix) % 10;
			for(int j=0; j<10; j++)
			{
				if(tmp==j)
				addend(DL[j], a[m]);
			}
		}
		
		int c=0;
		for(int k=0; k<10; k++)
		{
			while(DL[k]->bptr->data1!=-1)
			{
				a[c] = deletefront(DL[k]);
				c++;
			}
		}
		
	}
	
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<" ";
	}
	
	return 0;
	
}


