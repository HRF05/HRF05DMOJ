#include <iostream>
using namespace std;

int main()
{
	int n, a;
	char b;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>a;
		cin>>b;
		for(int y = 0; y < a; y++)
		{
			cout<<b;
		}
		cout<<endl;
	}
}