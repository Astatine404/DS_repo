#include<iostream>
using namespace std;

void mergeArr(int a[], int b[], int m, int n, int i)
{
	if(i==n)
	{
		for(int i=0; i<m+n; i++)
		{
			cout<<a[i]<<" ";
		}
	}
	else
	{
		a[m+i]=b[i];
		mergeArr(a,b,m,n,i+1);
	}
}

int main()
{
	int a[10]={1,3,4,5,7}, b[5]={2,4,6,8,9};
	mergeArr(a,b,5,5,0);
}
