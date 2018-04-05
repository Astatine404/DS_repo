#include<iostream>
using namespace std;

void analyse(int a[], int i, int n)
{
	static int max=a[0], min=a[0], sum=0;
	if(i==n)
	{
		cout<<max<<" "<<min<<" "<<sum/n;
	}
	else
	{
		if(max<a[i])
		max=a[i];
		if(min>a[i])
		min=a[i];
		sum = sum + a[i];
		analyse(a, i+1, n);
	}
}

int main()
{
	int a[9] = {9,4,1,2,3,5,6,7,8};
	analyse(a,0,9);
	return 0;
}
