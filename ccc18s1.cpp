#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	long double c, k[100], smallest = 1000000000;
	cin >> c;
	
	for (int j = 0; j < c; j++)
	{
		cin >> k[j];
	}
	for (int i = 0; i < c - 1; i++)
	{
		for (int j = 0; j < c - i - 1; j++)
		{
			if (k[j] > k[j + 1])
			{

				int t = k[j];
				k[j] = k[j + 1];
				k[j + 1] = t;
			}
		}
	}
	for (int i = 1; i < c - 1; i++)
	{
		long double mid = k[i] / 2, midl = k[i - 1] / 2, midr = k[i + 1] / 2, units = (mid - midl) + (midr - mid);
		if (units < smallest && units != 0)
		{
			smallest = units;
		}
	}
	cout << fixed << setprecision(1) << smallest << endl;
}