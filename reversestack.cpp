#include<iostream>
#include "intqueue.h"
#include "intstack.h"
using namespace std;

int main()
{
	struct queue q;
	struct intstack s;
	int tmp;
	
	s.size = 10;
	s.top = -1;
	q.size = 10;
	q.f = -1; q.r = -1;
	cout<<"Enter elements in stack: ";
	for(int i=0; i<10; i++)
	{
		cin>>tmp;
		intstkpush(&s, tmp);
	}
	while(!intstkempty(s))
	{
		tmp = intstkpop(&s);
		enqueue(&q, tmp);
	}
	//printq(q); cout<<endl;
	while(!isemptyq(q))
	{
		tmp = dequeue(&q);
		intstkpush(&s, tmp);
	}
	
	while(!intstkempty(s))
	{
		cout<<intstkpop(&s)<<" ";
	}
	return 0;
}
