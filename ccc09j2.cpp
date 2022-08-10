#include <iostream>
using namespace std;

int main()
{
	int trout, pickerel, pike, total, a = 0;
	cin >> trout;
	cin >> pike;
	cin >> pickerel;
	cin >> total;
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			for (int z = 0; z < 101; z++)
			{
				if ((trout * i) + (pike * j) + (pickerel * z) <= total && i + j + z != 0)
				{
					cout << i << " Brown Trout, " << j << " Northern Pike, " << z << " Yellow Pickerel" << endl;
					a = a + 1;
					
				}
			}
		}
	}
	cout << "Number of ways to catch fish: " << a << endl;
}