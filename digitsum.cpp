#include<iostream>
using namespace std;

int sumd(int n)
{
	if(n<10)
		return n;
	else
		return n%10 + sumd(n/10);
}

int main()
{
	int a=153;
	cout<<sumd(a);
}
