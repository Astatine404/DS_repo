#include<iostream>
#include "intqueue.h"
using namespace std;

int main()
{
	int n;
	cout<<"No. of elements: "; cin>>n;
	int a[n], tmp;
	struct queue q[10];
	cout<<"Enter the elements: ";
	for(int i=0; i<n; i++)
	cin>>a[i];
	//Initializing queues
	for(int i=0; i<10; i++)
	{
		q[i].f = -1; q[i].r = -1;
		q[i].size = 10;
	}
	//Sorting
	for(int i=0, radix=1; i<5; i++, radix *= 10)
	{
		for(int m=0; m<n; m++)
		{
			tmp = (a[m]/radix)%10;
			for(int j=0; j<10; j++)
			{
				if(tmp == j)
				enqueue(&q[j], a[m]);
			}
		}
		int p=0;
		for(int m=0; m<10; m++)
		{
			while(!isemptyq(q[m]))
			{
				tmp = dequeue(&q[m]);
				a[p] = tmp;
				p++;
			}
		}
	}
	//Print sorted array
	for(int i=0; i<n; i++)
	cout<<a[i]<<" ";
	return 0;
}
