#include <iostream>
using namespace std;

int main()
{
	int n, d;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cin>>d;
		if(d < 46 || d > 314)
		{
			cout<<"N"<<endl;
		}
		else if(d > 225)
		{
			cout<<"W"<<endl;
		}
		else if(d < 134)
		{
			cout<<"E"<<endl;
		}
		else
		{
			cout<<"S"<<endl;
		}
	}
}