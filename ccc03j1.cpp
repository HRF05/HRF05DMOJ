#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; i < a; i++)
	{
		for (int y = 0; y < 3; y++)
		{
			cout << "*";
			if (y != 2)
			{
				for (int z = 0; z < b; z++)
				{
					cout << " ";
				}
			}
		}
		cout << endl;
	}
	for (int i = 0; i < (b * 2) + 3; i++)
	{
		cout << "*";
	}
	cout<<endl;
	for (int i = 0; i < c; i++)
	{
		for (int y = 0; y < b + 1; y++)
		{
			cout << " ";
		}
		cout << "*"<<endl;
	}
}