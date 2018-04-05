#include<iostream>
#include<string.h>
using namespace std;


typedef struct Data
{
	char* data;
} dta;

struct queue
{
	int f;
	int r;
	int size;
	dta elements[50];
};

int isemptyq(queue q)
{
	if (q.f == -1)
	return 1;
	else
	return 0;
}

int isfullq(queue q)
{
	if (q.f == (q.r+1)%q.size)
	return 1;
	else 
	return 0;
}

void enqueue(queue *q, char* x)
{
	if(isfullq(*q))
	cout<<"Queue is full";
	else if(isemptyq(*q))
	{
		q->f = 0;
		q->r = ((q->r)+1)%(q->size);
		strcpy(q->elements[q->r].data, x);
	}
	else
	{
		q->r = ((q->r)+1)%(q->size);
		strcpy(q->elements[q->r].data, x);
	}
}

char* dequeue(queue *q)
{
	if(isemptyq(*q))
	cout<<"Queue is empty";
	else if(q->f==q->r)
	{
		char* tmp = q->elements[q->f].data;
		q->f = -1; q->r = -1;
		return tmp;
	}
	else
	{
		char* tmp = q->elements[q->f].data;
		q->f = ((q->f)+1)%(q->size);
		return tmp;
	}
}

void printq(queue q)
{
	for(int i=q.f; i<=q.r; i++)
	cout<<q.elements[i].data<<" ";
}
