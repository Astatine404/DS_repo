#include<iostream>
//#include "linkedlist.h"
using namespace std;

typedef struct lnode
{
	int coeff;
	int exp;
	struct lnode *next;
} lptr;

void addend(lptr *L, int k1, int k2)
{
	if(L->coeff==-1&&L->exp==-1)
	{
		L->coeff=k1;
		L->exp=k2;
		L->next=NULL;
	}
	else
	{
		lptr *T;
		while(L->next!=NULL)
		L=L->next;
		T=new(lnode);
		T->coeff=k1;
		T->exp=k2;
		T->next=NULL;
		L->next=T;
	}
}

int main()
{
	lptr *L1, *L2, *L3, *T, *S; int tmp1, tmp2, n1, n2, s;
	//Initializing List
	L1 = new(lnode); L2 = new(lnode); L3 = new(lnode);
	L1->coeff=-1; L1->exp=-1; L1->next=NULL; L2->coeff=-1; L2->next=NULL; L3->data=-1; L3->next=NULL;
	cout<<"Number of terms in polynomial 1: "; cin>>n1;
	cout<<"Number of terms in polynomial 2: "; cin>>n2;
	cout<<"Enter coefficient and exponents in polynomial 1: ";
	for(int i=0; i<n1; i++)
	{
		cin>>tmp1>>tmp2;
		addend(L1, tmp1, tmp2);
	}
	cout<<"Enter coefficient and exponents in polynomial 2: ";
	for(int i=0; i<n2; i++)
	{
		cin>>tmp1>>tmp2;
		addend(L2, tmp1, tmp2);
	}
	S = L3;
	while(L1!=NULL&&L2!=NULL)
	{
		if(L1->exp>L2->exp)
		{
			L3->exp = L1->exp;
			L3->coeff = L1->coeff;
			L1 = L1->next;
		}
		else if(L1->exp<L2->exp)
		{
			L3->exp = L2->exp;
			L3->coeff = L2->coeff;
			L2 = L2->next;
		}
		else
		{
			L3->exp = L2->exp;
			L3->coeff = L2->coeff+L1->coeff;
			L2 = L2->next;
			L1 = L1->next;
		}
		T=new(lnode);
		T->next=NULL;
		L3->next=T;
	}
	while(L1!=NULL&&L2!=NULL)
	{
		if(L1!=NULL)
		{
			L3->exp = L1->exp;
			L3->coeff = L1->coeff;
			L1= L1->next;
		}
		else if(L2!=NULL)
		{
			L3->exp = L2->exp;
			L3->coeff = L2->coeff;
			L2= L2->next;
		}
		T=new(lnode);
		T->next=NULL;
		L3->next=T;
	}
	//Display new polynomial
	while(S!=NULL)
	{
		cout<<S->coeff<<" "<<S->exp<<'\t';
		S = S->next;
	}
}
	
	
	
