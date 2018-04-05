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


btptr **search(btptr **root, int k)
{
	if((*root)!=NULL)
	{
		if((*root)->data == k)
		return root;
		else if(k < (*root)->data)
		return search(&(*root)->lchild, k);
		else if(k > (*root)->data)
		return search(&(*root)->rchild, k);
	}
	else
	{
		cout<<"Not Found!\n";
		return NULL;
	}
}


void deleteNode(btptr **T)
{
	//Base case
	if((*T)==NULL) { }
	
	else if((*T)->lchild==NULL&&(*T)->rchild==NULL)
	{
		(*T) = NULL;
	}
	//If one child
	else if((*T)->lchild==NULL&&(*T)->rchild!=NULL)
	{
		if((*T)->rchild->lchild!=NULL)
		{
			(*T)->data = (*T)->rchild->lchild->data;
			deleteNode(&(*T)->rchild->lchild);
		}
		else
		{
			(*T)->data = (*T)->rchild->data;
			deleteNode(&(*T)->rchild);
		}
	}
	else if((*T)->rchild==NULL&&(*T)->lchild!=NULL)
	{
		if((*T)->lchild->rchild!=NULL)
		{
			(*T)->data = (*T)->lchild->rchild->data;
			deleteNode(&(*T)->lchild->rchild);
		}
		else
		{
			(*T)->data = (*T)->lchild->data;
			deleteNode(&(*T)->lchild);
		}
	}
	
	//If two children
	else if((*T)->lchild->rchild!=NULL)
	{
		(*T)->data = (*T)->lchild->rchild->data;
		deleteNode(&(*T)->lchild->rchild);
	}
	else if((*T)->rchild->lchild!=NULL)
	{
		(*T)->data = (*T)->rchild->lchild->data;
		deleteNode(&(*T)->rchild->lchild);
	}
	
	else
	{
		(*T)->data = (*T)->lchild->data;
		deleteNode(&(*T)->lchild);
	}

}

//Driver Function
void searchNdelete(btptr **root, int key)
{
	btptr **node = search(root, key); 
	//cout<<node->data<<endl;
	if(*node != NULL)
	deleteNode(node);
}

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
	preorder(T); cout<<endl;
	
	while(true)
	{
		cout<<"Delete which one? "; cin>>key;
		if(key==99)
		break;
		else {
			searchNdelete(&T, key);
			preorder(T); cout<<endl;
		}
	}
	
	return 0;
}
