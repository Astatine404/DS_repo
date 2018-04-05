#include<iostream>
using namespace std;



struct intstack
{
	int size;
	int top;
	int elements[50];
};

int intstkfull(intstack);
int intstkempty(intstack);
void intstkpush(intstack*, int);
int intstkpop(intstack*);
int intstkget(intstack);

int intstkfull(intstack s)
{
	if (s.top == (s.size) - 1)
	return 1; 
	else 
	return 0;
}

int intstkempty(intstack s)
{
	if (s.top == -1) 
	return 1;
	else 
	return 0;
}

void intstkpush(intstack *s, int k)
{
	if (intstkfull(*s))
	cout<<"Stack is full";
	else
	s->top++;
	s->elements[s->top] = k;
}

int intstkpop(intstack *s)
{
	if (intstkempty(*s))
	cout<<"Stack is empty";
	else
	return (s->elements[s->top--]);
}

int intstkget(intstack s)
{
	if (intstkempty(s)){
		
	}
	else
	return (s.elements[s.top]);
}

void prints(intstack s)
{
	for(int i=0; i<s.size; i++)
	cout<<s.elements[i]<<" ";
}
