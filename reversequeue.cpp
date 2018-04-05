#include<iostream>
#include "queue.h"
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
	cout<<"Enter elements in queue: ";
	for(int i=0; i<10; i++)
	{
		cin>>tmp;
		enqueue(&q, tmp);
	}
	while(!isemptyq(q))
	{
		tmp = dequeue(&q);
		intstkpush(&s, tmp);
	}
	//prints(s); cout<<endl;
	while(!intstkempty(s))
	{
		tmp = intstkpop(&s);
		enqueue(&q, tmp);
	}
	
	printq(q);
	return 0;
}
