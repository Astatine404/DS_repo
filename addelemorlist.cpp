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
		cout<<'(';
		print(ML->data.mlink);
		cout<<')';
		ML->tag = 2;
		print(ML->next);
	
	}
	else if(ML->tag==2)
	{
		print(ML->next);
	}
}

void addelem(mlptr *curr, char k)
{
	int trig = 0;
	if(curr->tag==0&&curr->next==NULL)
	{
	
		if(curr->data.ch=='\0')
		{
			//curr->tag=0;
			curr->data.ch=k;
			//curr->next=NULL;
			trig = 1;
		}
	}
	if(trig == 0)
	{
		while(curr->next!=NULL)
		curr = curr->next;
		mlptr *T;
		T = new(mlnode);
		T->tag = 0;
		T->data.ch = k;
		curr->next = T;
		T->next=NULL;
	}
}

mlptr* addlist(mlptr *curr)
{
	if(curr->tag==0&&curr->next==NULL)
	{
		if(curr->data.ch=='\0')
		{
			curr->tag = 1;
			mlptr *T;
			T = new(mlnode);
			T->tag = 0;
			T->data.ch = '\0';
			T->next = NULL;
			curr->data.mlink = T;
			return T;
		}
	}
	else
	{
		while(curr->next!=NULL)
		curr = curr->next;
		mlptr *T, *T1;
		T1 = new(mlnode);
		T1->tag=1;
		T1->next = NULL;
		T = new(mlnode);
		T->tag = 0;
		T->data.ch = '\0';
		T->next = NULL;
		T1->data.mlink = T;
		curr->next = T1;
		return T;
	}
}

int main()
{
	mlptr *ML[4];
	//Initialize MList
	ML[0] = new(mlnode);
	ML[0]->tag = 0;
	ML[0]->data.ch = '\0';
	ML[0]->next = NULL;
	
	addelem(ML[0], 'a');
	addelem(ML[0], 'b');
	addelem(ML[0], 'c');
	ML[1] = addlist(ML[0]);
	ML[2] = addlist(ML[1]);
	addelem(ML[2], 'm');
	addelem(ML[2], 'n');
	addelem(ML[2], 'o');
	addelem(ML[1], 'j');
	addelem(ML[1], 'k');
	addelem(ML[1], 'l');
	addelem(ML[0], 'd');
	addelem(ML[0], 'e');
	ML[4] = addlist(ML[0]);
	addelem(ML[4], 'f');
	addelem(ML[4], 'g');
	addelem(ML[0], 'h');
	addelem(ML[0], 'i');
	print(ML[0]);
	return 0;
}
