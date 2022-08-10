#include <iostream>
using namespace std;

int main()
{
	int b;
	cin >> b;
	int p = 5 * b - 400;
	cout << p << endl;
	if (p < 100) //above sea lvl
	{
		cout << "1" << endl;
		return 0;
	}
	else if (p == 100)//at sea lvl
	{
		cout << "0" << endl;
		return 0;
	}
	else if (p > 100)//bellow sea lvl
	{
		cout << "-1" << endl;
		return 0;
	}
}
