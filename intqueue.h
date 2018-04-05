#include<iostream>
using namespace std;

struct queue
{
	int f;
	int r;
	int size;
	int elements[50];
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

void enqueue(queue *q, int x)
{
	if(isfullq(*q))
	cout<<"Queue is full";
	else if(isemptyq(*q))
	{
		q->f = 0;
		q->r = ((q->r)+1)%(q->size);
		q->elements[q->r]=x;
	}
	else
	{
		q->r = ((q->r)+1)%(q->size);
		q->elements[q->r]=x;
	}
}

int dequeue(queue *q)
{
	if(isemptyq(*q))
	cout<<"Queue is empty";
	else if(q->f==q->r)
	{
		int tmp = q->elements[q->f];
		q->f = -1; q->r = -1;
		return tmp;
	}
	else
	{
		int tmp = q->elements[q->f];
		q->f = ((q->f)+1)%(q->size);
		return tmp;
	}
}

int peek(queue q)
{
	return q.elements[q.f];
}

void printq(queue q)
{
	for(int i=0; i<q.size; i++)
	cout<<q.elements[i]<<" ";
}
