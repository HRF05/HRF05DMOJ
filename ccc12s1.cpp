#include <iostream>
using namespace std;

int main()
{
	int a, combos = 0;
	cin>>a;
	for(int i = 0; i < a - 1; i++)
	{
		for(int y = 0; y < i; y++)
		{
			for(int k = 0; k < y; k++)
			{
				combos = combos + 1;
			}
		}
	}
	cout<<combos<<endl;
}