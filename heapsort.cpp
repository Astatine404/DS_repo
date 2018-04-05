#include <iostream>
using namespace std;



typedef struct hnode
{
	struct hnode *lchild;
	struct hnode *par;
	int data;
	struct hnode *rchild;
} hptr;

void swap(int *p, int *q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
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

hptr *heapify(hptr *T, int H[], int s, int i, hptr *par)
{
	if(i<=(s-1)/2)
	{
		T = new(hnode);
		T->data = H[i];
		T->par = par;
		T->lchild = heapify(T, H, s, 2*i, T);
		T->rchild = heapify(T, H, s, 2*i + 1, T);
	}
	else
	return T;
}

void heapsort(int H[], int s)
{
	while(s!=1)
	{
		cout<<H[1]<<" ";
		H[1] = H[s];
		int i = 1; s--;
		while(i<=(s-1)/2)
		{
			if(H[2*i + 1]>H[2*i])
			{
				swap(&H[i], &H[2*i]);
				i = 2*i;
			}
			else if(H[2*i]>H[2*i + 1])
			{
				swap(&H[i], &H[2*i + 1]);
				i = 2*i + 1;
			}
		}
	}
}

int main()
{
	int a[100], size=0;
	int t; hptr *T; a[0] = 0;
	while(true)
	{
		cin>>t;
		if(t==99)
		break;
		else
		heapadd(a, &size, t);
		for(int i =1; i<=size; i++)
		cout<<a[i]<<" ";
		cout<<endl;
	}
	heapsort(a, size);
}

