#include <iostream>
#include "math.h"
#include <iomanip>
using namespace std;

int main()
{
	double p;
	cin >> p;
	double y;
	cin >> y;
	double n;
	cin >> n;
	double y2;
	cin >> y2;
	double yeardiff = y2 - y;
	double increase = p / 100;
	double population = n * pow(1 + increase, yeardiff);
	if (yeardiff == 0)
	{
		cout << n;
	}
	else
	{
		cout << fixed << setprecision(0) << population << endl;
	}
	return 0;
}