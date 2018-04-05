#include<iostream>
#include "intqueue.h"
using namespace std;

void swap(int *p, int *q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
}

int main()
{
	int sets=0, top, a, b, tmp;
	int curr = 0;
	struct queue q, c[10];
	q.r = -1; q.f = -1; q.size = 40;
	for(int i=0; i<10; i++)
	{
		c[i].r = -1; c[i].f = -1; c[i].size = 40;
	}
	//Taking input 
	while(true)
	{
		cin>>tmp;
		if(tmp==99)
		break;
		enqueue(&q, tmp);
	}
	
	
	
	top = 0; a = 0;
	while(!isemptyq(q))
	{
		if(a==0)
		a = dequeue(&q);
		b = dequeue(&q);
		//Swapping
		if(a<b)
		swap(&a, &b);
		if(top==0)
		{
			top = b;
			enqueue(&c[curr], top);
		}
		else
		{
			if(top<b)
			{
				top = b;
				enqueue(&c[curr], top);
				//b = dequeue(&q);
			}
			else
			{
				enqueue(&c[curr], a);
				curr++;
				top = 0;
				a = b;
			}
		}
	}
	
	for(int i=0; i<=curr; i++)
	{
		while(!isemptyq(c[i]))
		cout<<dequeue(&c[i])<<" ";
		cout<<endl;
	}
	
}
