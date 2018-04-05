#include<iostream>
using namespace std;

void initSet(int S[])
{
	for(int i=1; i<10; i++)
	S[i] = i;
}

void add(int S[], int i, int j)
{
	int tmp = S[i];
	for(int k=1; k<=10; k++)
	{
		if(S[k]==tmp)
		S[k] = S[j];
	}
}


int check(int S[], int i, int j)
{
	if(S[i]==S[j])
	return 1;
	else
	return 0;
}


int main()
{
	int S[10], ch, i, j;
	initSet(S);
	while(true)
	{
		cout<<"\n1) Union\n2) Check\nChoice?";
		cin>>ch;
		if(ch==1)
		{
			cout<<"Enter pair? "; cin>>i>>j;
			add(S, i, j);
		}
		else if(ch==2)
		{
			cout<<"Enter pair? "; cin>>i>>j;
			cout<<check(S, i, j);
		}
	}
}
