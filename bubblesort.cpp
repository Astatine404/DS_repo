#include<iostream>
#include "linkedlist.h"
using namespace std;

int size(lptr *L)
{
	int count = 0;
	while(L!=NULL)
	{
		count++;
		L = L->next;
	}
	return count;
}

int main()
{
	lptr *L1, *T; int tmp, n;
	//Initializing List
	L1 = new(lnode);
	L1->data=-1; L1->next=NULL;
	cout<<"Enter number of elements: "; cin>>n;
	cout<<"Enter elements ";
	for(int i=0; i<n; i++)
	{
		cin>>tmp;
		addend(L1, tmp);
	}
	
	//Bubble Sort
	for(int i=0; i<n; i++)
	{
		T = L1;
		while(L1->next!=NULL)
		{
			if(L1->data>L1->next->data)	
			{
				tmp = L1->data;
				L1->data = L1->next->data;
				L1->next->data = tmp;
			}
			L1 = L1->next;
		}
		L1 = T;
	}
	printall(L1);
	return 0;
}
