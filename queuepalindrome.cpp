#include<iostream>
#include "charqueue.h"
#include<string.h>
using namespace std;

int main()
{
	struct queue q;
	char tpstr[2];
	char tmp;
	int n;
	tpstr[1] = '\0';
	q.f = -1; q.r = -1;
	cout<<"How many elements? "; cin>>n;
	char str[n]; str[0]='\0';
	char revstr[n]; revstr[0]='\0';
	q.size = n;
	cout<<"Enter elements in queue: ";
	while(!isfullq(q))
	{
		cin>>tpstr[0];
		enqueue(&q, tpstr[0]);
		printq(q); cout<<endl;
		strcat(str, tpstr);
	}
	cout<<str<<endl;
	for(int i=0; i<q.size; i++)
	{
		tmp = dequeue(&q);
		enqueue(&q, tmp);
	}
	while(!isemptyq(q))
	{
		tpstr[0] = dequeue(&q);
		strcat(revstr, tpstr);
	}
	cout<<revstr<<endl;
	if(!strcmp(str, revstr))
	cout<<"Palindrome";
	else
	cout<<"Not palindrome";
	return 0;
	
}
