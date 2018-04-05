#include <iostream>
#include "intqueue.h"
using namespace std;



const int d = 1;

typedef struct bdnode
{
	int cnt;
	int k[2*d+1];
	struct bdnode *ptr[2*d+2];
	struct bdnode *pptr;
	int y;
} bdptr;

void inorder(bdptr*);
bdptr *newNode(void);
bdptr **search(bdptr**, int);
int isfull(bdptr*);
void swapint(int*, int*);
void swapptr(bdptr**, bdptr**);
void sort(bdptr*, int);
void overflow(bdptr*, bdptr**, int, bdptr*, bdptr*);
void insert(bdptr*, bdptr**, int, bdptr*, bdptr*);
void insertKey(bdptr**, int);

void assign_y(bdptr *T, int k)
{
	if(T!=NULL)
	{
		T->y = k;
		for(int i=0; i<=T->cnt; i++)
		assign_y(T->ptr[i], k+1);
	}
}

void levelorder_main(bdptr *T, queue q[], int *max)
{
	if(T!=NULL)
	{
		for(int i =0; i<T->cnt; i++)
		enqueue(&q[T->y], T->k[i]);
		if(T->y>(*max))
		*max = T->y;
		for(int i=0; i<=T->cnt; i++)
		levelorder_main(T->ptr[i], q, max);
	}
}

void levelorder(bdptr *T)
{
	struct queue q[10]; int max = 0;
	//Initialize queue
	for(int i=0; i<10; i++)
	{
		q[i].f = -1; q[i].r = -1; q[i].size = 20;
	}
	assign_y(T, 0);
	levelorder_main(T, q, &max);
	//Print queues
	for(int i=0; i<=max; i++)
	{
		while(!isemptyq(q[i]))
		cout<<dequeue(&q[i])<<" ";
		cout<<endl;
	}
}

void inorder(bdptr *T)
{
	if(T!=NULL)
	{
		cout<<"(";
		for(int i=0; i<T->cnt; i++)
		{
			inorder(T->ptr[i]);
			cout<<T->k[i]<<" ";
		}
		inorder(T->ptr[T->cnt]);
		cout<<")";
	}
}



bdptr *newNode()
{
	bdptr *T;
	T = new(bdnode);
	T->cnt = 0;
	for(int i=0; i<2*d+2; i++)
	{
		T->ptr[i] = NULL;
		if(i!=2*d+1)
		T->k[i] = 999;
	}
	T->pptr = NULL;
	return T;
}

bdptr **search(bdptr **root, int key)
{
	if((*root)->cnt!=0)
	{
		for(int i=0; i<(*root)->cnt; i++)
		{
			if(key<(*root)->k[i])
			{
				if((*root)->ptr[i]!=NULL)
				return search(&(*root)->ptr[i], key);
				else
				return root;
			}
			else if(i==(*root)->cnt - 1)
			{
				if((*root)->ptr[i+1]!=NULL)
				return search(&(*root)->ptr[i+1], key);
				else
				return root;
			}
		}
	}
	else
	return root;
}

int isfull(bdptr *T)
{
	if(T->cnt >= 2*d)
	return 1;
	else
	return 0;
}

void swapint(int *x, int *y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

void swapptr(bdptr **x, bdptr **y)
{
	bdptr *T = *x;
	*x = *y;
	*y = T;
}

void sort(bdptr *T, int overflow)
{
	int j;
	if(overflow==0)
	{
		j = T->cnt - 1;
		while(T->k[j]<T->k[j-1]&&j>=1)
		{
			swapint(&T->k[j], &T->k[j-1]);
			swapptr(&T->ptr[j], &T->ptr[j-1]);
			j--;
		}
	}
	else if(overflow==1)
	{
			j = 2*d;
			while(T->k[j]<T->k[j-1]&&j>=1)
			{
				if(j==2*d)
				T->ptr[j+1] = T->ptr[j];
				swapint(&T->k[j], &T->k[j-1]);
				swapptr(&T->ptr[j], &T->ptr[j-1]);
				j--;
			}
	}
	else if(overflow==2)
	{
		for(int j=0; j<2*d; j++)
		{
			if(T->k[j]>T->k[j+1])
			{
				swapint(&T->k[j], &T->k[j+1]);
				swapptr(&T->ptr[j], &T->ptr[j+1]);
			}
		}
	}
}

//Overflow creation
void overflow(bdptr *T, bdptr **root, int key, bdptr *prevL, bdptr *prevR)
{
	bdptr *lchild, *rchild;
	lchild = newNode();
	rchild = newNode();
	int median = T->k[d];
	
	T->ptr[d] = prevL;
	T->ptr[d+1] = prevR;
 	
	//Create left child
	lchild->cnt = d;
	for(int i=0; i<d; i++)
	{
		lchild->ptr[i] = T->ptr[i];
		lchild->k[i] = T->k[i];
	}
	lchild->ptr[d] = T->ptr[d];
	
	//Creating right child
	rchild->cnt = d;
	for(int i=d+1; i<2*d+1; i++)
	{
		rchild->k[i-d-1] = T->k[i];
		rchild->ptr[i-d-1] = T->ptr[i];
	}
	rchild->ptr[d] = T->ptr[2*d+1];
	
	//Insert median to parent
	if(T->pptr!=NULL)
	{
		cout<<"Parent present, inserting median to parent...";
		insert(T->pptr, root, median, lchild, rchild);
	}
	else
	{
		cout<<"Parent not present, creating new node...";
		bdptr *P;
		P = newNode();
		lchild->pptr = P;
		rchild->pptr = P;
		insert(P, root, median, lchild, rchild);
		*root = P;
	}	
}

//Main insert function
void insert(bdptr *T, bdptr **root, int key, bdptr *lchild, bdptr *rchild)
{
	if(!isfull(T))
	{
		T->cnt++;
		T->k[T->cnt - 1] = key;
		T->ptr[T->cnt] = T->ptr[T->cnt-1];
		sort(T, 0);
		int pos=-1;
		for(int i=0; i<T->cnt; i++)
		{
			if(key==T->k[i])
			{
				pos = i;
				break;
			}
		}
		if(pos==-1)
		cout<<"Insert Error!";
		if(lchild!=NULL)
		lchild->pptr = T;
		if(rchild!=NULL)
		rchild->pptr = T;
		T->ptr[pos] = lchild;
		T->ptr[pos+1] = rchild;
	}
	else
	{
		//Overflow and allocate new node
		cout<<"Full, checking if non-full sibling available....";
		int trig = 0;
		T->k[T->cnt] = key;
		sort(T, 1);
		if(T->pptr!=NULL)
		{
			int pos=0;
			while(pos<=T->pptr->cnt)
			{
				if(T->pptr->ptr[pos]==T)
				break;
				pos++;
			}
			//Check right sibling
			if(pos<T->pptr->cnt)
			{
				if(T->pptr->ptr[pos+1]!=NULL)
				{
					if(!isfull(T->pptr->ptr[pos+1]))
					{
						trig = 1;
						insert(T->pptr->ptr[pos+1], root, T->pptr->k[pos], NULL, NULL);
						T->pptr->k[pos] = T->k[T->cnt];
					}
				}
			}
			if(trig!=1&&pos!=0)
			{
				//Check left sibling
				if(T->pptr->ptr[pos-1]!=NULL)
				{
					if(!isfull(T->pptr->ptr[pos-1]))
					{
						trig = 1;
						insert(T->pptr->ptr[pos-1], root, T->pptr->k[pos-1], NULL, NULL);
						T->pptr->k[pos-1] = T->k[0];
						T->k[0] = 1000;
						sort(T, 2);
					}
				}
			}
		}
		if(trig==0)
		{
			cout<<"Non-full sibling not available";
			overflow(T, root, key, lchild, rchild);
		}
		else
		cout<<"available...";
		cout<<"done\n";
	}
}

//Helper function for insertion
void insertKey(bdptr **root, int key)
{
	bdptr **T;
	T = search(root, key);
	insert(*T, root, key, NULL, NULL);
}

void getPath(bdptr *T)
{
	if(T!=NULL)
	{
		for(int i=0; i<T->cnt; i++)
		cout<<T->k[i]<<" ";
		cout<<"|";
		getPath(T->pptr);
	}
}

int main()
{
	bdptr *T, **temp; int tmp;
	label:
	T = newNode();
	while(true)
	{
		cin>>tmp;
		if(tmp==99)
		{
			inorder(T);
			cout<<endl;
			levelorder(T);
			continue;
		}
		else if(tmp==100)
		goto label;
		else if(tmp==101)
		{
			cout<<"Enter next element: "; cin>>tmp;
			temp = search(&T, tmp);
			getPath(*temp);
			continue;
		}
		insertKey(&T, tmp);
	}
	return 0;
}
