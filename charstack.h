#include<iostream>
using namespace std;



struct stack
{
	int size;
	int top;
	char elements[50];
};

int stkfull(stack);
int stkempty(stack);
void stkpush(stack*, char);
char stkpop(stack*);
char stkget(stack);

int stkfull(stack s)
{
	if (s.top == (s.size) - 1)
	return 1; 
	else 
	return 0;
}

int stkempty(stack s)
{
	if (s.top == -1) 
	return 1;
	else 
	return 0;
}

void stkpush(stack *s, char k)
{
	if (stkfull(*s))
	cout<<"Stack is full";
	else
	s->top++;
	s->elements[s->top] = k;
}

char stkpop(stack *s)
{
	if (stkempty(*s))
	cout<<"Stack is empty";
	else
	return (s->elements[s->top--]);
}

char stkget(stack s)
{
	if (stkempty(s)){
		
	}
	else
	return (s.elements[s.top]);
}
