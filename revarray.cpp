#include<iostream>
using namespace std;

void revArray(int a[], int n, int i)
{
	if(i==(n/2))
	{
		for(int i=0;i<n;i++)
		cout<<a[i]<<" ";
	}
	else
	{
		int temp = a[i];
		a[i] = a[n-i-1];
		a[n-i-1] = temp;
		revArray(a,n,i+1);
	}
}

int main()
{
	int a[10] = {1,2,3,4,5,6,7,8,9,0};
	revArray(a,10,0);
	return 0;
}
