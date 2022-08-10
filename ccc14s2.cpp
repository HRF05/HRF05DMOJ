#include <iostream>
using namespace std;

int main()
{
	int c;
	string a[100], b[100];
	cin>>c;
	for(int i = 0; i < c; i++)
	{
		cin>>a[i];
	}
	for(int i = 0; i < c; i++)
	{
		cin>>b[i];
	}
	for(int i = 0; i < c; i++)
	{
		if(a[i] == b[i])
		{
			cout<<"bad";
			return 0;
		}
		for(int y = 0; y < c; y++)
		{
			if(a[i] == b[y] || b[i] == a[y])
			{
				if(a[i] != b[y] || b[i] != a[y])
				{
					cout<<"bad";
					return 0;
				}
			}
		}
	}
	cout<<"good"<<endl;
}