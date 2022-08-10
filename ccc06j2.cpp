#include <iostream>
using namespace std;

int main()
{
	int a, b, c = 0;
	cin>>a>>b;
	for(int i = 1; i <= a; i++)
	{
		for(int y = 1; y <= b; y++)
		{
			if(i + y == 10)
			{
				c += 1;
			}
		}
	}
	if(c == 1)
	{
		cout<<"There is "<<c<<" way to get the sum 10."<<endl;
	}
	else
	{
		cout<<"There are "<<c<<" ways to get the sum 10."<<endl;
	}
}