#include <iostream>
using namespace std;

int main()
{
	int n, a, b, sa = 100, sb = 100;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		cin >> b;
		if (a == b)
		{

		}
		else if (a > b)
		{
			sb -= a;
		}
		else if (b > a)
		{
			sa -= b;
		}
	}
	cout << sa << endl << sb << endl;
}