#include <iostream>
using namespace std;

int main()
{
	int y[10000];
	int c;
	cin >> c;
	for (int i = 1; i <= c; ++i)
	{
		cin >> y[i];
	}
	
	
	for (int x = 1; x <= c; ++x)
	{
		if((y[x] % 4 == 0 && (y[x] % 100 < 0 || y[x] % 100 > 0)) || (y[x] % 400 == 0))
		{
			cout << "1" << endl;
		}
		else
		{
			cout << "0" << endl;
		}
	}
	
	return 0;
}