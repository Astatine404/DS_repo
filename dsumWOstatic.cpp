#include<iostream>
using namespace std;

int s=0;

void sumd(int a)
{
	if(a==0)
	cout<<s;
	else
	{
		s = s + a%10;
		sumd(a/10);
	}
}

int main()
{
	int a = 7582;
	sumd(a);
	return 0;
}
