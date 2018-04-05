#include<iostream>
using namespace std;

void printd(int n)
{
	if(n<10)
	{
		cout<<n<<" ";
	}
	else
	{
		printd(n/10);
		cout<<n%10<<" ";
	}
}

int main()
{
	int a = 7582;
	printd(a);
	return 0;
}
