#include <iostream>
using namespace std;

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


void fill(int a[], int *aptr, adptr *A)
{
	while(A!=NULL)
	{
		a[*aptr] = A->av->data;
		*aptr++;
		A = A->avnext;
	}
}

void convert(gptr *T)
{
	int aptr=0, vptr=0;
	int a[40], v[10];
	while(T!=NULL)
	{
		v[vptr] = aptr;
		fill(a, &aptr, T->alist);
		vptr++;
		T= T->vnext;
	}
	for(int i=0; i<vptr; i++)
	cout<<v[i]<<" ";
	cout<<endl;
	for(int i=0; i<aptr; i++)
	cout<<a[i]<<" ";
}



int main()
{

}
