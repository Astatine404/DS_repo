#include <iostream>
#include "linkedlist.h"
using namespace std;

int main()
{
	lptr *L;
	L = new(lnode);
	L->data=-1; L->next=NULL;
	int tmp;
	for(int i=0; i<5; i++)
	{
		cin>>tmp;
		addend(L, tmp);
	}
	addfront(&L, 27);
	addafter(L, 3, 94);
	cout<<deleteend(L)<<endl;
	printall(L);
	return 0;
}
