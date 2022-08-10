#include <iostream>
using namespace std;

int main()
{
	int w1;
	int w2;
	int w3;
	cin >> w1;
	cin >> w2;
	cin >> w3;
	if ((w1 > w2 && w1 < w3) || (w1 > w3 && w1 < w2))
	{
		cout << w1 << endl;
		return 0;
	}
	else if((w2 > w1 && w2 < w3) || (w2 > w3 && w2 < w1))
	{
		cout << w2 << endl;
		return 0;
	}
	else if((w3 > w2 && w3 < w1) || (w3 > w1 && w3 < w2))
	{
		cout << w3 << endl;
		return 0;
	}
}