#include<iostream>
#include"genstack.h"
#include<string.h>
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
	char instr[40], convstr[40], outstr[40];
	cout<<"Enter the string:"; cin>>instr;
	strcpy(convstr, strrev(instr));
	for(int i=0; i<strlen(convstr); i++)
	{
		if(convstr[i]=='(')
		convstr[i]=')';
		else if(convstr[i]==')')
		convstr[i]='(';
	}
	cout<<convstr<<endl;
	char tmpStr[2]; tmpStr[1] = '\0', outstr[0]='\0';
	int step;
	
	//Initialize Stack
	s.top=-1; s.size = strlen(convstr);
	
	//Add string elements to stack
	for(int i=0; i<strlen(convstr); i++)
	{
		if(isalpha(convstr[i])||isdigit(convstr[i]))
		{
			tmpStr[0] = convstr[i];
			strcat(outstr, tmpStr);
		}
		else if(convstr[i]=='(')
			charstkpush(&s, convstr[i]);
		else if(convstr[i]==')')
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
				charstkpush(&s, convstr[i]);
			else if(precedence(convstr[i])>precedence(charstkget(s)))
				charstkpush(&s, convstr[i]);
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
	
	cout<<strrev(outstr);
}
