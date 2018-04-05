#include<iostream>
#include "linkedlist.h"
using namespace std;

int isemptystk(lptr *L)
{
	if(L->data==-1)
	return 1;
	else
	return 0;
}

int isfullstk(lptr *L, int size)
{
	int i=1;
	while(L->next!=NULL)
	{
		L=L->next;
		i++;	
	}
	if(i==size)
	return 1;
	else
	return 0;
}

void push(lptr **L, int stksize, int k)
{
	if(!isfullstk(*L, stksize))
	addfront(L, k);
	else
	cout<<"Stack is full";
}

int pop(lptr **L)
{
	if(!isemptystk(*L))
	return deletefront(L);
	else
	cout<<"Stack is empty";
}

int main()
{
	lptr *L;
	int stksize, tmp;
	//Initializing List
	L = new(lnode);
	L->data=-1; L->next=NULL;
	cout<<"Stack size?"; cin>>stksize;
	//Fill stack
	for(int i=0; i<stksize; i++)
	{
		cin>>tmp;
		push(&L, stksize, tmp);
	}
	//Print List
	printall(L);
	
	for(int i = 0; i<3; i++)
	{
		cout<<pop(&L)<<" ";
	}
	cout<<endl;
	printall(L);
	return 0;
}
