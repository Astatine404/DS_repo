#include<iostream>
#include "linkedlist.h"
using namespace std;

lptr* sort(lptr **L1, lptr **L2)
{
	if((*L1)->data==-1) { 
		return (*L2);
	}
	else
	{
		int trig = 0;
		int tmp = deletefront(L1);
		if(tmp<((*L2)->data))
		{
			addfront(L2, tmp);
			goto skip;
		}
		lptr *T;
		T = (*L2);
		while((*L2)->next!=NULL)
		{
				if(tmp>((*L2)->data)&&tmp<((*L2)->next->data))
				{
					addafter(T, (*L2)->data, tmp);
					trig = 1;
					break;
				}
			(*L2) = (*L2)->next;
		}
		(*L2) = T;
		if(trig==0)
		{
			addend((*L2), tmp);
		}
		skip:
		sort(L1, L2);
	}
}

int main()
{
	lptr *L1, *L2; int n, tmp;
	//Initializing List
	L1 = new(lnode); L2 = new(lnode);
	L1->data=-1; L1->next=NULL; L2->data=-1; L2->next=NULL;
	cout<<"Enter number of elements: "; cin>>n;
	cout<<"Enter elements ";
	for(int i=0; i<n; i++)
	{
		cin>>tmp;
		addend(L1, tmp);
	}
	
	//Insertion Sort

	addend(L2, deletefront(&L1));
	printall(sort(&L1, &L2));
	return 0;
}
