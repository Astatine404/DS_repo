#include <iostream>
#include "linkedlist.h"
using namespace std;

int isemptyq(lptr *L)
{
	if(L->data==-1)
	return 1;
	else
	return 0;
}

int isfullq(lptr *L, int size)
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

void enqueue(lptr *L, int size, int k)
{
	if(!isfullq(L, size))
	{
		addend(L, k);
	}
	else
	cout<<"Queue is full";
}

int dequeue(lptr **L)
{
	if(!isemptyq(*L))
	return deletefront(L);
	else
	cout<<"The queue is empty";
}

int main()
{
	lptr *L;
	int qsize, tmp;
	//Initializing List
	L = new(lnode);
	L->data=-1; L->next=NULL;
	cout<<"Queue size?"; cin>>qsize;
	
	//Fill queue
	for(int i=0; i<qsize; i++)
	{
		cin>>tmp;
		enqueue(L, qsize, tmp);
	}
	//Print List
	printall(L);
	
	for(int i = 0; i<3; i++)
	{
		cout<<dequeue(&L)<<" ";
	}
	cout<<endl;
	printall(L);
	return 0;
}
