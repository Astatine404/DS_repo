#include<iostream>
#include "linkedlist.h"
using namespace std;

int main()
{
	lptr *L1, *L2, *T; int tmp, n, trig=0, s, tmps=0;
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
	cout<<"Enter required sum:"; cin>>s;
	
	//Insertion Sort

	addend(L2, deletefront(&L1));
	//printall(L2);
	while(L1->data!=-1)
	{
		trig = 0;
		tmp = deletefront(&L1);
		if(tmp<(L2->data))
		{
			addfront(&L2, tmp);
			//printall(L2);
			continue;
		}
		T = L2;
		while(L2->next!=NULL)
		{
			//if(L2->next->next!=NULL)
			//{
				if(tmp>(L2->data)&&tmp<(L2->next->data))
				{
					addafter(T, L2->data, tmp);
					trig = 1;
					break;
				}
			//}
			L2 = L2->next;
		}
		L2 = T;
		if(trig==0)
		{
			addend(L2, tmp);
		}
		
		//printall(L2);
	}
	printall(L2);
	
	while(L2!=NULL)
	{
		
	}
}
