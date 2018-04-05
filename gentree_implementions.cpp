#include <iostream>
using namespace std;

typedef struct gtnode1
{
	char data;
	int cnt;
	struct gtnode1 *child[100];
} gptr1;

gptr1 *newNode(int k)
{
	gptr1 *G;
	G = new(gtnode1);
	G->data = k;
	for(int i=0; i<100; i++)
	G->child[i] = NULL;
	return G;
}

void create(gptr1 **G)
{
	static int k, cnt;
	if((*G)==NULL)
	{
		cout<<"Enter data of current node:"; cin>>k;
		(*G) = newNode(k);
		cout<<"Enter number of children:"; cin>>(*G)->cnt;
		cout<<"Enter children:";
		for(int i=0; i<(*G)->cnt; i++)
		{
			create(&(*G)->child[i]);
		}
	}
}


struct gtnode2_cld
{
	struct gtnode2 *tptr;
	struct gtnode2_cld *next;
};

typedef struct gtnode2
{
	char data;
	struct gtnode2_cld *cldlist;
} gptr2;

typedef struct gtnode3
{
	struct gtnode3 *fcld;
	char data;
	struct gtnode3 *nsib;
} gptr3;




int main()
{
	gptr1 *G;
	G = NULL;
	create(&G);
	
}


