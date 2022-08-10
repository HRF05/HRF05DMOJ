#include <iostream>
using namespace std;

int main()
{
	int c, a, k[100], g = 0, total = 0;
	cin >> a; 
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
	for (int i = 0; i < c; i++) 
	{
		if (total + k[i] <= a)
		{
			g = g + 1;
			total = total + k[i];
		}
		else
		{
			i = c + 1;
		}
	}
	cout << g << endl;
}