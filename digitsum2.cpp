#include<iostream>
using namespace std;

void sumd(int n)
{
	static int s=0;
	if(n==0)
		cout<<s;
	else
	{
		s = s + n%10;
		sumd(n/10);
	}
}

int main()
{
	int a = 153;
	sumd(a);
}
