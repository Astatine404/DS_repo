#include <iostream>
#include "bst.h"
using namespace std;



//Testing Main
int main()
{
	btptr *T; int i, n;
	while(true)
	{
		cin>>i;
		if(i==99) break;
		insert(&T, i);
	}
	repeat:
	cout<<"Which key?"; cin>>n;
	btptr *node = *search(&T, n);
	cout<<getHeight(node);
	goto repeat;
	return 0;
}
