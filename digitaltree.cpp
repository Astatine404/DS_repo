#include <iostream>
#include <string.h>
using namespace std;

typedef struct dnode
{
	struct dnode *lchild;
	char data[30];
	struct dnode *rchild;
} dptr;

dptr *newNode(char* k)
{
	dptr *T;
	T = new(dnode);
	strcpy(T->data, k);
	T->lchild = NULL; T->rchild = NULL;
	return T;
}

void insert(dptr **T, char* k, int i)
{
	if((*T)==NULL)
	{
		(*T) = newNode(k);
	}
	else
	{
		if(k[i]=='0')
		{
			insert(&(*T)->lchild, k, i+1);
		}
		else if(k[i]=='1')
		{
			insert(&(*T)->rchild, k, i+1);
		}
	}
}

int search(dptr *T, char *k, int i)
{
	static int save;
	if(T!=NULL)
	{
		
		if(T->data[i]==k[i])
		{
			int trig = 1;
			for(int j=i; j<strlen(T->data); j++)
			{
				if(T->data[j]==k[j])
				continue;
				else
				{
					trig = 0;
					break;
				}
			}
			if(trig==1)
			return 1;
			else
			{
				if(k[i]=='0')
				return search(T->lchild, k, i+1);
				else if(k[i]=='1')
				return search(T->rchild, k, i+1);
			}
		}
		else if(k[i]=='0')
		return search(T->lchild, k, i+1);
		else if(k[i]=='1')
		return search(T->rchild, k, i+1);
	}
	else
	return 0;
}

int main()
{
	dptr *T; char str[30]; T = NULL;
	while(true)
	{
		cin>>str;
		if(!strcmp(str, "stop"))
		break;
		insert(&T, str, 0);
	}
	
	char sch[30];
	cout<<"What to search? "; cin>>sch;
	cout<<search(T, sch, 0);
}
