#include <iostream>
using namespace std;

typedef struct btnode
{
	struct btnode *lchild;
	char cdata;
	int idata;
	struct btnode *rchild;
} btptr;

btptr *newNode(int idat, char cdat)
{
	btptr *tmp;
	tmp = new(btnode);
	tmp->idata = idat; tmp->cdata = cdat; tmp->lchild = NULL; tmp->rchild = NULL;
	return tmp;
}

//Orders for checking
void inorder(btptr *T)
{
	if(T!=NULL)
	{
		inorder(T->lchild);
		cout<<T->cdata<<" ";
		inorder(T->rchild);
	}
}

void preorder(btptr *T)
{
	if(T!=NULL)
	{
		cout<<T->idata<<" ";
		preorder(T->lchild);
		preorder(T->rchild);
	}
}

//Insert Function for BST
void insert(btptr **T, int idat, char cdat)
{
	if((*T)==NULL)
	{
		(*T) = newNode(idat, cdat);
	}
	else if((int)cdat < (int)((*T)->cdata))
	{
		insert(&(*T)->lchild, idat, cdat);
	}
	else if((int)cdat > (int)((*T)->cdata))
	{
		insert(&(*T)->rchild, idat, cdat);
	}
	else
	cout<<"Error!";
}


void searchbyint(btptr **root, int k, btptr **ptr)
{
	if((*root)!=NULL)
	{
		if((*root)->idata == k)
		{
			cout<<"Found"; *ptr = new(btnode);
			*ptr = *root;
		}
		else
		{
			searchbyint(&(*root)->lchild, k, ptr);
			searchbyint(&(*root)->rchild, k, ptr);
		}
	}
}

btptr **searchbychar(btptr **root, char k)
{
	if((*root)!=NULL)
	{
		if((*root)->cdata == k)
		return root;
		else if((int)k < (int)((*root)->cdata))
		return searchbychar(&(*root)->lchild, k);
		else if((int)k > (int)((*root)->cdata))
		return searchbychar(&(*root)->rchild, k);
	}
	else
	{
		cout<<k<<" Not Found!\n";
		return NULL;
	}
}

void rotateleft(btptr **k1, btptr **k3)
{
	btptr *tmp = *k1;
	*k1 = *k3;
	tmp->rchild = (*k3)->lchild;
	(*k1)->lchild = tmp;
}

void rotateright(btptr **k1, btptr **k3)
{
	btptr *tmp = *k1;
	*k1 = *k3;
	tmp->lchild = (*k3)->rchild;
	(*k1)->rchild = tmp;
}



void getPath(btptr *T, int newval, int pathArr[], int pathlen, int resultArr[], int *finallen)
{
	if(T!=NULL)
	{
		pathArr[pathlen] = T->idata;
		pathlen++;
		
		if(T->lchild==NULL&&T->rchild==NULL)
		{
			if(T->idata==newval)
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

void insertNbal(btptr **T, int idat, char cdat)
{
	int pathArr[100], resultArr[100];
	insert(T, idat, cdat);
	cout<<"\nInserted";
	int unbal=0, len=0; btptr **ptr1, **ptr3;
	getPath(*T, idat, pathArr, 0, resultArr, &len);
	cout<<"\nPath: ";
	for(int i=0; i<len; i++)
	cout<<resultArr[i]<<" ";
	cout<<endl;
	for(int i=len-1; i>=2; i--)
	{
		searchbyint(T, resultArr[i-2], ptr1);
		searchbyint(T, resultArr[i-1], ptr3);
		if((*ptr1)->idata>(*ptr3)->idata)
		{
			if((*ptr1)->rchild==(*ptr3))
			rotateleft(ptr1, ptr3);
			else if((*ptr1)->lchild==(*ptr3))
			rotateright(ptr1, ptr3);
			else
			cout<<"Balance error!";
		}
	}
	preorder(*T); cout<<" | "; inorder(*T); cout<<endl; cout<<"---------";
}

//Testing Main
int main()
{
	btptr *T; int ikey; char ckey; T = NULL;
	//Test segment
	cout<<(int)'A';
	while(true)
	{
		cout<<"\nEnter next char and int pair:";
		cin>>ckey;
		cin>>ikey;
		if(ikey==99)
		break;
		else
		{
			insertNbal(&T, ikey, ckey);
		}
	}
	preorder(T); cout<<endl;
	cout<<T->idata; cout<<endl;
	
}

