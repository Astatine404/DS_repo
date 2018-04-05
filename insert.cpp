#include <iostream>
using namespace std;

typedef struct btnode
{
	struct btnode *lchild;
	int data;
	struct btnode *rchild;
} btptr;

btptr *newNode(int k)
{
	btptr *tmp;
	tmp = new(btnode);
	tmp->data = k; tmp->lchild = NULL; tmp->rchild = NULL;
	return tmp;
}

//Preorder for checking
void preorder(btptr *T)
{
	if(T!=NULL)
	{
		preorder(T->lchild);
		cout<<T->data<<" ";
		preorder(T->rchild);
	}
}

//Insert Function for BST
void insert(btptr **T, int key)
{
	if((*T)==NULL)
	{
		(*T) = newNode(key);
	}
	else if(key < (*T)->data)
	{
		insert(&(*T)->lchild, key);
	}
	else if(key > (*T)->data)
	{
		insert(&(*T)->rchild, key);
	}
	else
	cout<<"Error!";
}

//Testing main
int main()
{
	btptr *T; int key; T = NULL;
	while(true)
	{
		cin>>key;
		if(key==99)
		break;
		else
		insert(&T, key);
	}
	preorder(T);
	return 0;
		
}
