#include <iostream>
using namespace std;

typedef struct dhnode
{
	int data;
	struct dhnode *pptr;
	struct dhnode *cld[3]; 
} dhptr;

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
		if(H[pos]<H[(pos+1)/3])
		swap(&H[pos], &H[(pos+1)/3]);
		pos = (pos+1)/3;
	}
}

dhptr *heapify(dhptr *T, int H[], int s, int i, dhptr *par)
{
	if(i<=(s-1)/3)
	{
		T = new(dhnode);
		T->data = H[i];
		T->pptr = par; dhptr *P[3];
		T->cld[0] = heapify(P[0], H, s, 3*i - 1, T);
		T->cld[1] = heapify(P[1], H, s, 3*i, T);
		T->cld[2] = heapify(P[2], H, s, 3*i + 1, T);
	}
	else
	return T;
}

int main()
{
	int a[100], size=0;
	int t; dhptr *D, *tmp; a[0] = 0;
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
	D = heapify(tmp, a, size, 1, NULL);
}
