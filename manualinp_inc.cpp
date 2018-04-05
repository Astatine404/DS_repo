#include <iostream>
using namespace std;

typedef struct mlnode
{
	int tag;
	union u
	{
		char ch;
		struct mlnode *mlink;
	} data;
	struct mlnode *next;
} mlptr;

void print(mlptr *ML)
{
	if(ML==NULL) { }
	else if(ML->tag == 0)
	{
		cout<<ML->data.ch;
		print(ML->next);
	}
	else if(ML->tag==1)
	{
		cout<<"(";
		print(ML->data.mlink);
		cout<<")";
	}
}

void addelem(mlptr *ML, char t)
{
	ML->tag = 0;
	ML->data.ch= t;
}

mlptr newbranch(mlptr *ML)
{
	ML->tag = 1;
	ML->data.mlink = 
}

int main()
{
	struct mlnode *ML;
	ML = NULL;
	char str[20]; int choice;
	cout<<"Enter required string: ";
	cin>>str;
	for(int i=0; i<strlen(str); i++)
	{
		if(ML==NULL)
		{
			ML = new(mlnode);
			ML->next = NULL;
		}
		if(str[i]=='(')
		{
			
			
		}
	}
}
