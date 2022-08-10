#include <iostream>
using namespace std;

int main()
{
	int i, l, l1, l2, l3, l4, l5, lf[10001], c = 0;
	bool b[10001];
	for (i = 0; i < 10000; i++)
	{
		cin >> l;
		if (l == 99999)
		{
			i = 10000;
		}
		else
		{
			c = c + 1;
		}
		l1 = (l / 10000) % 10;
		l2 = (l / 1000) % 10;
		l3 = (l / 100) % 10;
		l4 = (l / 10) % 10;
		l5 = l % 10;
		int s = l1 + l2;
		lf[i] = l3 * 100 + l4 * 10 + l5;
		if (l1 + l2 == 0)
		{
			if (b[i-1] == true)
			{
				b[i] = true;
			}
			else
			{
				b[i] = false;
			}
		}
		else if (s % 2 == 0)
		{
			b[i] = true;
		}
		else if(s % 2 != 0)
		{
			b[i] = false;
		}


	}
	for (i = 0; i < c; i++)
	{

		if (b[i] == true)
		{
			cout << "right " << lf[i] << endl;
		}
		else
		{
			cout << "left " << lf[i] << endl;
		}
		

	}
}