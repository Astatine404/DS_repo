#include<iostream>
using namespace std;

void swap(int *p, int *q)
{
	int tmp= *p;
	*p = *q;
	*q = tmp;
}


void partition(int a[], int low, int high, int n)
{
	if(high-low>1)
	{
		int l=low+1, h=high, p, j;
		p = a[low];
		while(l<h)
		{
			while(a[l]<p)
			{
				l++;
			}
			while(a[h]>p)
			{
				h--;
			}
			swap(&a[l], &a[h]);
		}
		swap(&a[l], &a[h]);
		int c[20], cptr=0;
		for(int i=low+1; i<=h; i++)
		{
			c[cptr] = a[i];
			cptr++;
		}
		c[cptr] = p; j=cptr; cptr++;
		for(int i=l; i<=high; i++)
		{
			c[cptr] = a[i];
			cptr++;
		}
		int cpos=0;
		for(int i=low; i<=high; i++)
		{
			a[i] = c[cpos];
			cpos++;
		}
		for(int i=0; i<=n-1; i++)
		cout<<a[i]<<" ";
		cout<<endl;
		partition(a, low, j-1, n);
		partition(a, j+1, high, n);
	}
}

int main()
{
	int a[20], n;
	cout<<"How many? "; cin>>n;
	for(int i=0; i<n; i++)
	cin>>a[i];
	partition(a, 0, n-1, n);
	for(int i=0; i<n; i++)
	cout<<a[i]<<" ";
}
