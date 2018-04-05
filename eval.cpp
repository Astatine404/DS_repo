#include <iostream>
#include "charstack.h"
#include <string.h>
using namespace std;

//Global Variables
char lvl1[3] = "+-";
char lvl2[3] = "*/";
int strTrig = 0;
int stkTrig = 0;

void strpwr(char str)
{
	for(int j=0; j<2; j++)
	{
		if (str==lvl1[j])
		{
			strTrig = 1;
			break;
		}
		else if (str==lvl2[j])
		{
			strTrig = 2;
			break;
		}
	}
}

void stkpwr(struct stack s)
{
	for(int j=0; j<2; j++)
	{
		if(stkget(s)==lvl1[j])
		{
			stkTrig = 1;
			break;
		}
		else if (stkget(s)==lvl2[j])
		{
			stkTrig = 2;
			break;
		}
	}
}

int main()
{
	struct stack s;
	s.size = 20;
	s.top = -1;
	char tmp='\0';
	
	char str[20];
	cout<<"Enter the expression: "; cin>>str;
	for(int i=0; i<strlen(str); i++)
	{
		if(isalpha(str[i]) || isdigit(str[i]))
		cout<<str[i];
		else if(str[i]=='(')
		{
			stkpush(&s, str[i]);
		}
		else if(str[i]==')')
		{
			tmp = stkpop(&s);
			while(tmp!='(')
			{
				tmp = stkpop(&s);
				//if(tmp!='(')
				cout<<tmp;
			}
			tmp='\0';
		}
		else
		{
			//Checking power of current string element
			strpwr(str[i]);
			
			label:
			//Checking power of stack top element
			stkpwr(s);
			
			if(stkTrig == 0) //That means it is '('
			{
				stkpush(&s, str[i]);
			}
			else if((strTrig == 1 && stkTrig == 1) || (strTrig == 2 && stkTrig == 2) || (strTrig == 1 && stkTrig == 2))
			{
				if(stkget(s)!='(')
				cout<<stkpop(&s);
				if(stkempty(s))
				stkpush(&s, str[i]);
				else
				goto label;
			}
			else if((strTrig == 2 && stkTrig == 1) || (strTrig == 1  && stkempty(s)) || (strTrig == 2 && stkempty(s)))
			{
				stkpush(&s, str[i]);
			}
		}	
		stkTrig = 0; strTrig = 0;
	}
	while(!stkempty(s))
	{
		cout<<stkpop(&s);
	}
	return 0;
}
