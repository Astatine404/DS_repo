#include<iostream>
using namespace std;


typedef union Data
{
	int a;
	char b;
} data;

struct genqueue 
{
	int f;
	int r;
	int size;
	data elements[50];
	int type[50];
};

int isemptyq(genqueue q)
{
	if(q.f == -1)
	return 1;
	else
	return 0;
}

int isfullq(genqueue q)
{
	if(q.f == (q.r+1)%q.size)
	return 1;
	else
	return 0;
}
void intenqueue(genqueue *q, int x)
{
	if (isfullq(*q))
	cout<<"Queue is full";
	else if(isemptyq(*q))
	{
		q->f=0;
		q->r=((q->r)+1)%q->size;
		q->elements[q->r].a=x;
		q->type[q->r]=0;
	}
	else
	{
		q->r = ((q->r)+1)%q->size;
		q->elements[q->r].a=x;
		q->type[q->r]=0;
	}
}

void charenqueue(genqueue *q, char x)
{
	if (isfullq(*q))
	cout<<"Queue is full";
	else if(isemptyq(*q))
	{
		q->f=0;
		q->r=((q->r)+1)%q->size;
		q->elements[q->r].b=x;
		q->type[q->r]=1;
	}
	else
	{
		q->r = ((q->r)+1)%q->size;
		q->elements[q->r].b=x;
		q->type[q->r]=1;
	}
}

int intdequeue(genqueue *q)
{
	if(isemptyq(*q))
	cout<<"Queue is empty";
	else if(q->f==q->r)
	{
		int tmp=q->elements[q->f].a;
		q->r = -1; q->f = -1;
		return tmp;
	}
	else
	{
		int tmp=q->elements[q->f].a;
		q->f = (q->f+1)%q->size;
		return tmp;
	}
	

}

char chardequeue(genqueue *q)
{
	if(isemptyq(*q))
	cout<<"Queue is empty";
	else if(q->f==q->r)
	{
		char tmp=q->elements[q->f].b;
		q->r = -1; q->f = -1;
		return tmp;
	}
	else
	{
		char tmp=q->elements[q->f].b;
		q->f = (q->f+1)%q->size;
		return tmp;
	}
}

int gettype(genqueue q, int x)
{
	return q.type[(q.f+x)%q.size];
}

int printq(genqueue q)
{
	while(!isemptyq(q))
	{
		if(gettype(q, 0)==0)
		{
			cout<<intdequeue(&q)<<" ";
		}
		else if(gettype(q, 0)==1)
		{
			cout<<chardequeue(&q)<<" ";
		}
	}
}

int getsize(genqueue q)
{
	int i=0;
	while(!isemptyq(q))
	{
		if(gettype(q, 0)==0)
		{
			intdequeue(&q);
		}
		else if(gettype(q, 0)==1)
		{
			chardequeue(&q);
		}
		i++;
	}
	return i;
}

