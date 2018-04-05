#include<iostream>
using namespace std;

void *func(int a, int b)
{
	int k=a+b;
	int *sum=&k;
	return sum;
}

int main()
{
	int a=3, b=5;
	void *p=func(a,b);
	cout<<*(int *)func(a,b);
	return 0;
}
