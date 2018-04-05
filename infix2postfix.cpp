//Infix to Postfix
#include<iostream>
#include "genstack.h"
#include<string.h>
#include<cstdlib>
using namespace std;

int precedence(char k)
{
	if(k=='*'||k=='/')
	return 2;
	else if(k=='+'||k=='-')
	return 1;
	else if(k=='(')
	return 0;
}

int main()
{
	struct genstack s;
	
	char instr[40], outstr[40], tmpStr[2]; tmpStr[1] = '\0', outstr[0]='\0';
	int step;
	cout<<"Enter the string:"; cin>>instr;
	
	//Initialize Stack
	s.top=-1; s.size = strlen(instr);
	
	//Add string elements to stack
	for(int i=0; i<strlen(instr); i++)
	{
		if(isalpha(instr[i])||isdigit(instr[i]))
		{
			tmpStr[0] = instr[i];
			strcat(outstr, tmpStr);
		}
		else if(instr[i]=='(')
			charstkpush(&s, instr[i]);
		else if(instr[i]==')')
		{
			tmpStr[0] = charstkpop(&s);
			while(tmpStr[0]!='(')
			{
				strcat(outstr, tmpStr);
				tmpStr[0] = charstkpop(&s);
				//prints(s); //cin>>step;
			}
			
		}
		else
		{
			label:
			if(genstkempty(s))
				charstkpush(&s, instr[i]);
			else if(precedence(instr[i])>precedence(charstkget(s)))
				charstkpush(&s, instr[i]);
			else
			{
				tmpStr[0]=charstkpop(&s);
				strcat(outstr, tmpStr);
				goto label;
			}
		}
		//prints(s); //cin>>step;
		
	}
	
	while(!genstkempty(s))
	{
		tmpStr[0] = charstkpop(&s);
		strcat(outstr, tmpStr);
	}
	
	cout<<outstr;
}
