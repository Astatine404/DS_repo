//STL Queue Demo
#include<iostream>
#include<queue>
using namespace std;

void printq(queue <int> q)
{
	while(!q.empty())
	{
		cout<<q.front()<<" ";
		q.pop();
	}
	cout<<endl;
}

int main()
{
	queue <int> q[3];
	for(int i=0; i<20; i++)
	{
		q[0].push(i);
	}
	printq(q[0]);
	while(!q[0].empty())
	{
		cout<<q[0].front()<<" "<<q[0].size();
		q[0].pop();
		cout<<endl;
	}
	return 0;
}
