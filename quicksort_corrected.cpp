#include<iostream>
using namespace std;

void swap(int *p, int *q)
{
	int tmp= *p;
	*p = *q;
	*q = tmp;
}

int partition(int a[], int low, int high, int n)
{
	if(low<high)
	{
		int l=low+1, h=high, p, j=0;
		p = a[low];
		while(l<=h)
		{
			while(a[l]<p)
			{
				l++;
			}
			while(a[h]>p)
			{
				h--;
			}
			if(l<=h)
			swap(&a[l], &a[h]);
		}
		swap(&a[low], &a[h]);
		for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
		cout<<endl;
		return h;
	}
}

void quicksort(int a[], int low, int high, int n)
{
	if(low<high)
	{
		int j = partition(a, low, high, n);
		quicksort(a, low, j-1, n);
		quicksort(a, j+1, high, n);
	}
}

int main()
{
	int a[20], n;
	cout<<"How many? "; cin>>n;
	for(int i=0; i<n; i++)
	cin>>a[i];
	quicksort(a, 0, n-1, n);
	for(int i=0; i<n; i++)
	cout<<a[i]<<" ";
}
