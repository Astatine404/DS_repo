//STL Stack Demo
#include<iostream>
#include<stack>
using namespace std;

int main()
{
	stack <int> s;
	for(int i=0; i<20; i++)
	{
		s.push(i);
	}
	while(!s.empty())
	{
		cout<<s.top()<<" "<<s.size();
		s.pop();
		cout<<endl;
	}
	return 0;
}
