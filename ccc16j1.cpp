#include <iostream>
using namespace std;

int main()
{
	string f0;
	string f1;
	string f2;
	string f3;
	string f4;
	string f5;
	cin >> f0;
	cin >> f1;
	cin >> f2;
	cin >> f3;
	cin >> f4;
	cin >> f5;
	int L = 0;
	int W = 0;

	if (f0 == "L")
	{
		L = L + 1;
	}
	if (f1 == "L")
	{
		L = L + 1;
	}
	if (f2 == "L")
	{
		L = L + 1;
	}
	if (f3 == "L")
	{
		L = L + 1;
	}
	if (f4 == "L")
	{
		L = L + 1;
	}
	if (f5 == "L")
	{
		L = L + 1;
	}
	if (f0 == "W")
	{
		W = W + 1;
	}
	if (f1 == "W")
	{
		W = W + 1;
	}
	if (f2 == "W")
	{
		W = W + 1;
	}
	if (f3 == "W")
	{
		W = W + 1;
	}
	if (f4 == "W")
	{
		W = W + 1;
	}
	if (f5 == "W")
	{
		W = W + 1;
	}
	
	
	if (L == 6)
	{
		cout << "-1" << endl;
		return 0;
	}
	else if (W == 3 || W == 4)
	{
		cout << "2" << endl;
	}
	else if (W == 5 || W == 6)
	{
		cout << "1" << endl;
	}
	else if (W == 1 || W == 2)
	{
		cout << "3" << endl;
	}
}