#include <iostream>
using namespace std;

typedef struct lnode
{
	int data;
	struct lnode *next;
} lptr;

void addend(lptr *L, int k)
{
	if(L->data==-1)
	{
		L->data=k;
		L->next=NULL;
	}
	else
	{
		lptr *T;
		while(L->next!=NULL)
		L=L->next;
		T=new(lnode);
		T->data=k;
		T->next=NULL;
		L->next=T;
	}
}

void completecircle(lptr *L)
{
	lptr *T;
	T = L;
	while(L->next!=NULL)
	L = L->next;
	L->next = T; 
}

int main()
{
	int n, k;
	cout<<"Enter total number of people: ";
	cin>>n;
	lptr *L , *T;;
	//Initialize list
	L = new(lnode);
	L->data = -1; L->next = NULL;
	for(int i=1; i<=n; i++)
	{
		addend(L, i);
	}
	completecircle(L);
	while(L->data!=L->next->data)
	{
		cout<<"Now at position "<<L->data<<endl;
		cout<<"Skip how many? "; cin>>k;
		for(int i=0; i<k; i++)
		L = L->next;
		cout<<L->next->data<<" is dead!"<<endl;
		T = L->next->next;
		L->next = T;
		L = L->next;
	}
	cout<<L->data<<" is saved!";
	return 0;
}
		
		
	
	
