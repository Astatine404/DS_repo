#include <iostream>
using namespace std;

//K-D Trees

typedef struct kdnode
{
	struct kdnode *lchild;
	int data[100];
	struct kdnode *rchild;
} kptr;

kptr *newNode(int key[], int k)
{
	kptr *K;
	K = new(kdnode);
	for(int i=0; i<k; i++)
	{
		K->data[i] = key[i];
	}
	K->lchild = NULL; K->rchild =NULL;
	return K;
}

void insert(kptr **K, int k, int key[], int i)
{
	if((*K)==NULL)
	{
		(*K) = newNode(key, k);
	}
	else
	{
		if(key[i]<(*K)->data[i])
		insert(&(*K)->lchild, k, key, (i+1)%k);
		else if(key[i]>(*K)->data[i])
		insert(&(*K)->rchild, k, key, (i+1)%k);
	}
}

int search(kptr *K, int k, int key[])
{
	static int i=-1; i = (i+1)%k;
	if(K!=NULL)
	{
		if(key[i]==K->data[i])
		{
			int trig = 1;
			for(int j=i; j<k; j++)
			{
				if(key[j]==K->data[j])
				continue;
				else
				{
					trig = 0;
					break;
				}
			}
			if(trig == 1)
			return 1;
		}
		if(key[i]<K->data[i])
		return search(K->lchild, k, key);
		else if(key[i]>K->data[i])
		return search(K->rchild, k, key);
	}
	else
	return 0;
}

int main()
{
	kptr *K; int k; K = NULL;
	cout<<"Enter k of Kd-tree"; cin>>k;
	int key[k];
	while(true)
	{
		cout<<"Enter the keys:";
		for(int i=0; i<k; i++)
		{
			cin>>key[i];
		}
		if(key[0] == 0)
		break;
		insert(&K, k, key, 0);
	}
	cout<<"What keys to search?";
	for(int i=0; i<k; i++)
	{
		cin>>key[i];
	}
	cout<<search(K, k, key);
}
