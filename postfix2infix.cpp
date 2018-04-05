#include<iostream>
#include"strstack.h"
#include<string.h>
using namespace std;

int main()
{
	struct strstack s;
	
	char instr[40], outstr[40], tmpStr[2]; tmpStr[1] = '\0', outstr[0]='\0';
	int step; char a[30], b[30];
	char tmp[60]; tmp[0] = '\0';
	cout<<"Enter the string:"; cin>>instr;
	
	//Initialize Stack
	s.top=-1; s.size = strlen(instr);
	
	//Add string elements to stack
	for(int i=0; i<strlen(instr); i++)
	{
		if(isalpha(instr[i])||isdigit(instr[i]))
		{
			tmpStr[0] = instr[i];
			stkpush(&s, tmpStr);
		}
		else
		{
			strcpy(a, stkpop(&s));
			strcpy(b, stkpop(&s));
			//tmpStr[0] = '('; strcat(tmp, tmpStr);
			strcat(tmp, b);
			tmpStr[0] = instr[i];
			strcat(tmp, tmpStr);
			strcat(tmp, a);
			stkpush(&s, tmp);
			tmp[0]='\0';
			//tmpStr[0] = ')'; strcat(tmp, tmpStr);
		}
	}
	if(s.top==0)
	cout<<stkpop(&s);
	else
	cout<<"Error";
	return 0;
}
