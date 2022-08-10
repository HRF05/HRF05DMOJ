#include <iostream>
using namespace std;

int main()
{
	double w;
	double h;
	cin >> w;
	cin >> h;
	double bmi = w / (h * h);
	if(bmi >= 25)
	{
		cout << "Overweight" << endl;
		return 0;
	}
	else if(bmi >= 18.5)
	{
		cout << "Normal weight" << endl;
	}
	else if(bmi >= 0)
	{
		cout << "Underweight" << endl;
	}
}