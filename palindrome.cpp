#include<iostream>
#include<string>
#include<string.h>
#include<cstdlib>
using namespace std;

int pal(int n)
{
	static int num1, num2;
	char x;
	if(n<10)
	{
		if(strcmp(str1))
		cout<<"It is a palindrome";
		else
		cout<<"It is not";
	}
	else
	{
		str1 = str1 + (char)n%10
		pal(n/10);
		str2 = str2 + (char)n%10
	}
}

int main()
{
	pal(1331);
	return 0;
}
