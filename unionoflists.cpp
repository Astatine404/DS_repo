#include<iostream>
#include "linkedlist.h"
using namespace std;

int main()
{
	lptr *L1, *L2, *L3, *T; int tmp;
	//Initializing List
	L1 = new(lnode); L2 = new(lnode); L3 = new(lnode);
	L1->data=-1; L1->next=NULL; L2->data=-1; L2->next=NULL; L3->data=-1; L3->next=NULL;
	for(int i=0; i<4; i++)
	{
		cin>>tmp;
		addend(L1, tmp);
	}
	
	for(int i=0; i<5; i++)
	{
		cin>>tmp;
		addend(L2, tmp);
	}
	
	while(L1!=NULL)
	{
		addend(L3, L1->data);
		L1 = L1->next;
	}
	//printall(L3);
	//printall(L2);
	while(L2!=NULL)
	{
		int trigger = 0;
		T = L3;
		while(L3!=NULL)
		{
			if(L3->data==L2->data)
			trigger = 1;
			L3 = L3->next;
		}
		L3 = T;
		if(trigger == 0)
		addend(L3, L2->data);
		L2 = L2->next;
	}
	printall(L3);
	return 0;
}
