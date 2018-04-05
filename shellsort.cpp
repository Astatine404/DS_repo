#include<iostream>
using namespace std;

void swap(int *p, int *q)
{
	int tmp = *p;
	*p = *q;
	*q = tmp;
}

void shellsort(int a[], int n)
{
	int k = n/2;
	while(true)
	{
		for(int i=0; i<(n-k); i++)
		{
			if(a[i]>a[i+k])
			swap(&a[i], &a[i+k]);
		}
		if(k%2!=0&&k!=1)
		k = (k+1)/2;
		else
		k = k/2;
		if(k==0)
		break;
	}
}

int main()
{
	int a[30], n;
	cout<<"How many?"; cin>>n;
	for(int i=0; i<n; i++)
	cin>>a[i];
	shellsort(a, n);
	for(int i=0; i<n; i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
