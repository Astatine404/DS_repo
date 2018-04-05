#include<iostream>
#include "intstack.h"
using namespace std;


int main()
{
	struct intstack s1, s2;
	int n, tmp, step, swp;
	cout<<"Enter size of array:"; cin>>n;
	int arr[n];
	//Initializing Stacks
	s1.size = n; s1.top = -1;
	s2.size = n; s2.top = -1;
	cout<<"Enter elements of array:";
	for(int i=0; i<n; i++)
	cin>>arr[i];
	
	
	
	for(int i=0; i<n; i++)
		intstkpush(&s1, arr[i]);
	
		
	for(int i=0; i<n; i++)
	{
		if(i%2==0)
		{
			while(!intstkempty(s1))
			{
				if(intstkempty(s2))
				intstkpush(&s2, intstkpop(&s1));
				else
				{
					tmp = intstkpop(&s1);
					if(tmp<intstkget(s2))
					{
						//Swapping
						swp = intstkpop(&s2);
						intstkpush(&s2, tmp);
						intstkpush(&s1, swp);
					}
					else
					intstkpush(&s2, tmp);
				}
			}
			arr[n-i-1] = intstkpop(&s2);
		}
		else
		{
			while(!intstkempty(s2))
			{
				if(intstkempty(s1))
				intstkpush(&s1, intstkpop(&s2));
				else
				{
					tmp = intstkpop(&s2);
					if(tmp<intstkget(s1))
					{
						//Swapping
						swp = intstkpop(&s1);
						intstkpush(&s1, tmp);
						intstkpush(&s2, swp);
					}
					else
					intstkpush(&s1, tmp);
				}
			}
			arr[n-i-1] = intstkpop(&s1);
		}
	}
	for(int i=0; i<n; i++)
	cout<<arr[i]<<" ";
}
