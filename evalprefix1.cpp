#include<iostream>
#include<string.h>
#include "genqueue.h"
#include<cstdlib>
using namespace std;

int main()
{
	struct genqueue q;
	q.f = -1; q.r = -1;
	//char op[5] = "+-*/";
	int tmpInt;
	char tmpChar[2]; tmpChar[1] = '\0';
	char tmp, step;
	char str[40];
	cout<<"Enter the prefix expression:";
	cin>>str;
	q.size=50;
	for(int i=0; i<strlen(str); i++)
	{
		tmpChar[0] = str[i];
		if(isdigit(str[i]))
		{
			intenqueue(&q, atoi(tmpChar));
		}
		else
		{
			charenqueue(&q, str[i]);
		}
		//cin>>step;
		printq(q); cout<<endl;
	}
	while(q.f!=q.r)
	{
		if(gettype(q, 0)==1&&gettype(q, 1)==0&&gettype(q, 2)==0)
		{
			char a = chardequeue(&q);
			int b = intdequeue(&q);
			int c = intdequeue(&q);
			a=='*'?tmpInt=b*c:(a=='/'?tmpInt=b/c:(a=='+'?tmpInt=b+c:(a=='-'?tmpInt=b-c:tmpInt=0)));
			intenqueue(&q, tmpInt);
		}
		else
		{
			if(gettype(q, 0)==0)
			{
				tmpInt = intdequeue(&q);
				intenqueue(&q, tmpInt);
			}
			else if(gettype(q, 0)==1)
			{
				tmp = chardequeue(&q);
				charenqueue(&q, tmp);
			}
		}
		cin>>step;
		printq(q); cout<<endl;
		/*strcpy(a, dequeue(&q));
		for(int i=0; i<4; i++)
		{
			if(a[0]==op[i])
			opTrig1 = 1;
		}
		if(opTrig1 == 1)
		{}
		else
		{
			enqueue(&q, a);
			continue;
		}
		strcpy(b, dequeue(&q));
		if(isdigit(b[0]))
		{}
		else
		{
			enqueue(&q, a);
			enqueue(&q, b);
			continue;
		}
		strcpy(c, dequeue(&q));
		if(isdigit(c[0]))
		{}
		else
		{
			enqueue(&q, a);
			enqueue(&q, b);
			enqueue(&q, c);
			continue;
		}*/
		
	}
	cout<<intdequeue(&q);
	return 0;
}
