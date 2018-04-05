#include<iostream>
#include "linkedlist.h"
using namespace std;

int main()
{
	lptr *L1, *M; int tmp, n;
	cout<<"Enter number of elements(odd): ";
	cin>>n;
	//Initializing List
	L1 = new(lnode);
	L1->data=-1; L1->next=NULL;
	M = L1;
	for(int i=0; i<n; i++)
	{
		cin>>tmp;
		addend(L1, tmp);
	}

	while(L1->next!=NULL)
	{
		L1 = L1->next->next;
		M = M->next;
	}
	
	cout<<M->data;
	return 0;
}
