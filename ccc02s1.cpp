#include <iostream>
using namespace std;

int main()
{
	int p, g, r, o, t, a = 0, m = 10000000;
	cin >> p;
	cin >> g;
	cin >> r;
	cin >> o;
	cin >> t;
	for (int i = 0; i < 101; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			for (int z = 0; z < 101; z++)
			{
				for (int x = 0; x < 101; x++)
				{
					if ((p * i) + (g * j) + (r * z) + (x * o) == t)
					{
						cout << "# of PINK is " << i << " # of GREEN is " << j << " # of RED is " << z << " # of ORANGE is " << x << endl;
						a = a + 1;
						if (i + j + z + x < m)
						{
							m = i + j + z + x;
						}
					}
				}

			}
		}
	}
	cout << "Total combinations is " << a << "."<<endl;
	cout << "Minimum number of tickets to print is " << m << "." << endl;
}