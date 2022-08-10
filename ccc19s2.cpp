#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n, b = 0, a;

	cin >> n;
	for (int z = 0; z < n; z++)
	{
		cin >> a;
		a = a * 2;
		for (int i = 2; i > 0; i++)
		{
			b = 0;
			for (int y = 2; y <= ceil(sqrt(i)); y++)
			{
				if (i % y == 0)
				{
					b = 1;
				}
			}
			if (b == 0)
			{
				for (int y = 2; y <= ceil(sqrt(a - i)); y++)
				{
					if ((a - i) % y == 0)
					{
						b = 1;
					}
				}
				if (b == 0)
				{
					cout << i << " " << a - i << endl;
					break;
				}
			}
		}
	}
}