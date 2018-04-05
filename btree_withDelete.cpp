#include <iostream>
#include "intqueue.h"
using namespace std;

const int d = 2;
const int enableRedist = 1;

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

bdptr **searchDelete(bdptr **root, int key)
{
	if((*root)->cnt!=0)
	{
		for(int i=0; i<(*root)->cnt; i++)
		{
			if(key==(*root)->k[i])
			return root;
			else if(key<(*root)->k[i])
			{
				if((*root)->ptr[i]!=NULL)
				return search(&(*root)->ptr[i], key);
			}
			else if(i==(*root)->cnt - 1)
			{
				if((*root)->ptr[i+1]!=NULL)
				return search(&(*root)->ptr[i+1], key);
			}
		}
	}
	else
	return root;
}

int isfull(bdptr *T)
{
	if(T->cnt >= 2*d+1)
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

void sort(bdptr *T, int tag)
{
	int j;
	if(tag==0)
	{
		j = T->cnt - 1;
		while(T->k[j]<T->k[j-1]&&j>=1)
		{
			if(j==2*d)
			T->ptr[j+1] = T->ptr[j];
			swapint(&T->k[j], &T->k[j-1]);
			swapptr(&T->ptr[j], &T->ptr[j-1]);
			j--;
		}
	}
	else if(tag==1)
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

void updateParent(bdptr *root)
{
	if(root!=NULL)
	{
		for(int i=0; i<=root->cnt; i++)
		{
			if(root->ptr[i]!=NULL)
			root->ptr[i]->pptr = root;
		}
		for(int i=0; i<=root->cnt; i++)
		updateParent(root->ptr[i]);
	}
}

//Overflow creation
void overflow(bdptr *T, bdptr **root)
{
	//Overflow and allocate new node
	int trig = 0;
	if(enableRedist==0)
	goto skip;
		
	cout<<"Full, checking if non-full sibling available....";
	if(T->pptr!=NULL)
	{
		int pos=-1;
		while(pos<=T->pptr->cnt)
		{
			if(T->pptr->ptr[pos]==T)
			break;
			pos++;
		}
		if(pos==-1)
		cout<<"Insert error!";
		//Check right sibling
		if(pos<T->pptr->cnt)
		{
			if(T->pptr->ptr[pos+1]!=NULL)
			{
				if(T->pptr->ptr[pos+1]->cnt<2*d)
				{
					trig = 1;
					insert(T->pptr->ptr[pos+1], root, T->pptr->k[pos], NULL, NULL);
					T->pptr->k[pos] = T->k[T->cnt-1];
					T->cnt--;
				}
			}
		}
		if(trig!=1&&pos!=0)
		{
			//Check left sibling
			if(T->pptr->ptr[pos-1]!=NULL)
			{
				if(T->pptr->ptr[pos-1]->cnt<2*d)
				{
					trig = 1;
					insert(T->pptr->ptr[pos-1], root, T->pptr->k[pos-1], NULL, NULL);
					T->pptr->k[pos-1] = T->k[0];
					T->k[0] = 999;
					sort(T, 1);
					T->cnt--;
				}
			}
		}
	}
	skip:
	if(trig==0)
	{
		if(enableRedist!=0)
		cout<<"Non-full sibling not available...splitting...";
		else
		cout<<"Full, splitting...";
		bdptr *lchild, *rchild;
		lchild = newNode();
		rchild = newNode();
		int median = T->k[d];
	
		
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
			updateParent(*root);
			insert(T->pptr, root, median, lchild, rchild);
			updateParent(*root);
		
		}
		else
		{
			cout<<"Parent not present, creating new node...";
			bdptr *P;
			P = newNode();
			updateParent(*root);
			insert(P, root, median, lchild, rchild);
			*root = P;
			updateParent(*root);
		}	
	}
	else
	{
		cout<<"available...";
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
		//Check if redist or split needed
		if(isfull(T))
		{
			//inorder(*root); cout<<endl;
			overflow(T, root);
			cout<<"done\n";
		}
	}
	else
	{
		//inorder(*root); cout<<endl;
		overflow(T, root);
		cout<<"done\n";
	}
}

void deleteb(bdptr *T, bdptr **root, int key, int tag)
{
	int loc=-1;
	for(int i=0; i<T->cnt; i++)
	{
		if(T->k[i]==key)
		{
			loc = i;
			break;
		}
	}
	if(loc==-1)
	cout<<"Delete error!";
	T->k[loc] = 999;
	sort(T, 1);
	T->cnt--;
	//Leaf Node
	if(T->ptr[loc]==NULL&&T->ptr[loc+1]==NULL)
	{
		//cout<<"Leaf node detected!\n";
		//Check for underflow
		if(T->cnt<d)
		{
			//Check for node redistribution
			int pos=-1 , trig=0;
			while(pos<=T->pptr->cnt)
			{
				if(T->pptr->ptr[pos]==T)
				break;
				pos++;
			}
			if(pos==-1)
			cout<<"Redist error!";
			//Check right sibling
			if(pos<T->pptr->cnt)
			{
				if(T->pptr->ptr[pos+1]!=NULL)
				{
					if(T->pptr->ptr[pos+1]->cnt>d)
					{
						trig = 1;
						insert(T, root, T->pptr->k[pos], NULL, NULL);
						T->pptr->k[pos] = T->pptr->ptr[pos+1]->k[0];
						deleteb(T->pptr->ptr[pos+1], root, T->pptr->ptr[pos+1]->k[0], 0);
					}
				}
			}
			if(trig!=1&&pos!=0)
			{
				//Check left sibling
				if(T->pptr->ptr[pos-1]!=NULL)
				{
					if(T->pptr->ptr[pos-1]->cnt>d)
					{
						trig = 1;
						insert(T, root, T->pptr->k[pos-1], NULL, NULL);
						T->pptr->k[pos-1] = T->pptr->ptr[pos-1]->k[T->pptr->ptr[pos-1]->cnt-1];
						deleteb(T->pptr->ptr[pos-1], root, T->pptr->ptr[pos-1]->k[T->pptr->ptr[pos-1]->cnt-1], 0);
					}
				}
			}
		
			if(trig==0)
			{
				//Node Combination
				cout<<"Node Combination required...";
				bdptr *P;
				P = newNode();
				P->cnt = 2*d;
				//Check right sibling
				if(pos<T->pptr->cnt)
				{
					if(T->pptr->ptr[pos+1]!=NULL)
					{
						if(T->pptr->ptr[pos+1]->cnt<=d)
						{
							trig = 1;
							//Copy current node to new node
							for(int i=0; i<T->cnt; i++)
							{
								P->ptr[i] = T->ptr[i];
								P->k[i] = T->k[i];
							}
							P->ptr[T->cnt] = T->ptr[T->cnt];
							//Put median in new node
							P->k[T->cnt] = T->pptr->k[pos];
							//Copy right sibling to new node
							for(int i=0; i<T->pptr->ptr[pos+1]->cnt; i++)
							{
								P->ptr[T->cnt+i+1] = T->pptr->ptr[pos+1]->ptr[i];
								P->k[T->cnt+i+1] = T->pptr->ptr[pos+1]->k[i];
							}
							P->ptr[P->cnt] = T->pptr->ptr[pos+1]->ptr[T->pptr->ptr[pos+1]->cnt];
							P->pptr = T->pptr;
							T->pptr->ptr[pos+1] = P;
							updateParent(*root);
							deleteb(T->pptr, root, T->pptr->k[pos], 0);
						}
					}
				}
				
				//Check left sibling
				if(trig!=1&&pos!=0)
				{
					if(T->pptr->ptr[pos-1]!=NULL)
					{
						if(T->pptr->ptr[pos-1]->cnt<=d)
						{
							trig = 1;
							//Copy left sibling to new node
							for(int i=0; i<T->pptr->ptr[pos-1]->cnt; i++)
							{
								P->ptr[i] = T->pptr->ptr[pos-1]->ptr[i];
								P->k[i] = T->pptr->ptr[pos-1]->k[i];
							}
							P->ptr[T->pptr->ptr[pos-1]->cnt] = T->pptr->ptr[pos-1]->ptr[T->pptr->ptr[pos-1]->cnt];
							//Copy median to new node
							P->k[T->pptr->ptr[pos-1]->cnt] = T->pptr->k[pos-1];
							//Copy current node to new node
							for(int i=0; i<T->cnt; i++)
							{
								P->ptr[T->pptr->ptr[pos-1]->cnt+i+1] = T->ptr[i];
								P->k[T->pptr->ptr[pos-1]->cnt+i+1] = T->k[i];
							}
							P->ptr[P->cnt] = T->ptr[T->cnt];
							P->pptr = T->pptr;
							T->pptr->ptr[pos-1] = P;
							updateParent(*root);
							deleteb(T->pptr, root, T->pptr->k[pos-1], 0);
						}
					}
				}
				cout<<"done\n";
			}
		}
	}
}

//Helper function for insertion
void insertKey(bdptr **root, int key)
{
	bdptr **T;
	T = search(root, key);
	insert(*T, root, key, NULL, NULL);
}

void deleteKey(bdptr **root, int key)
{
	bdptr **T;
	T = NULL;
	T = searchDelete(root, key);
	if (T==NULL)
	cout<<"Does this value even exist?";
	else
	deleteb(*T, root, key, 0);
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
		else if(tmp==102)
		{
			cout<<"Delete?";
			cin>>tmp;
			deleteKey(&T, tmp);
			continue;
		}
		insertKey(&T, tmp);
	}
	return 0;
}
