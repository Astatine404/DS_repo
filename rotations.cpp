#include <iostream>
#include "bst.h"
using namespace std;

void checkBal(btptr **T, int resultArr[], int len, int *unbal)
{
	if(T!=NULL)
	{
		int diff; btptr **curr;
		for(int i = len-1; i>=0; i--)
		{
			curr = search(T, resultArr[i]);
			diff = getHeight((*curr)->rchild) - getHeight((*curr)->lchild);
			if(diff>=2 || diff<=-2)
			{
				*unbal = (*curr)->data;
				break;
			}
		}
	}
}

void getPath(btptr *T, int newval, int pathArr[], int pathlen, int resultArr[], int *finallen)
{
	if(T!=NULL)
	{
		pathArr[pathlen] = T->data;
		pathlen++;
		
		if(T->lchild==NULL&&T->rchild==NULL)
		{
			if(T->data==newval)
			{
				for(int i=0; i<pathlen; i++)
				resultArr[i] = pathArr[i];
				*finallen = pathlen;
			}
		}
		else
		{
			getPath(T->rchild, newval, pathArr, pathlen, resultArr, finallen);
			getPath(T->lchild, newval, pathArr, pathlen, resultArr, finallen);
		}
	}
}

void rotateleft(btptr **k1, btptr **k3, btptr **k2)
{
	btptr *tmp = *k1;
	*k1 = *k3;
	tmp->rchild = (*k3)->lchild;
	(*k1)->lchild = tmp;
}

void rotateright(btptr **k1, btptr **k3, btptr **k2)
{
	btptr *tmp = *k1;
	*k1 = *k3;
	tmp->lchild = (*k3)->rchild;
	(*k1)->rchild = tmp;
}

void rotateleftright(btptr **k1, btptr **k3, btptr **k2)
{
	(*k3)->rchild = (*k2)->lchild;
	(*k2)->lchild = *k3;
	(*k1)->lchild = *k2;
	
	btptr *tmp = *k1;
	*k1 = *k2;
	tmp->lchild = (*k2)->rchild;
	(*k1)->rchild = tmp;
}

void rotaterightleft(btptr **k1, btptr **k3, btptr **k2)
{
	(*k3)->lchild = (*k2)->rchild;
	(*k2)->rchild = *k3;
	(*k1)->rchild = *k2;
	
	btptr *tmp = *k1;
	*k1 = *k2;
	tmp->rchild = (*k2)->lchild;
	(*k1)->lchild = tmp;
	
}

void insertNbal(btptr **T, int key)
{
	int pathArr[100], resultArr[100];
	insert(T, key);
	int k1, k3, k2, i=0, unbal=0, len=0; btptr **ptr1, **ptr3, **ptr2;
	getPath(*T, key, pathArr, 0, resultArr, &len);
	checkBal(T, resultArr, len, &unbal); cout<<"---------"<<endl; cout<<unbal<<endl; 
	if(unbal!=0)
	{
		while(resultArr[i]!=unbal)
		{i++;}
		k1 = resultArr[i]; ptr1 = search(T, k1);
		k3 = resultArr[i+1]; ptr3 = search(T, k3);
		k2 = resultArr[i+2]; ptr2 = search(T, k2);
		//Identify Shape
		if((*ptr1)->rchild==(*ptr3)&&(*ptr3)->rchild==(*ptr2))
		rotateleft(ptr1, ptr3, ptr2);
		else if((*ptr1)->rchild==(*ptr3)&&(*ptr3)->lchild==(*ptr2))
		rotaterightleft(ptr1, ptr3, ptr2);
		else if((*ptr1)->lchild==(*ptr3)&&(*ptr3)->lchild==(*ptr2))
		rotateright(ptr1, ptr3, ptr2);
		else if((*ptr1)->lchild==(*ptr3)&&(*ptr3)->rchild==(*ptr2))
		rotateleftright(ptr1, ptr3, ptr2);
	}
	preorder(*T); cout<<endl; cout<<"---------";
}

//Testing Main
int main()
{
	btptr *T; int key, step; T = NULL;
	while(true)
	{
		cin>>key;
		if(key==99)
		break;
		else
		insertNbal(&T, key);
	}
	preorder(T); cout<<endl;
	cout<<T->data; cout<<endl;
	
	
}
