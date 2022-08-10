#include <iostream>
using namespace std;

int main()
{
	int A1;
	int A2;
	int A3;
	cin >> A1;
	cin >> A2;
	cin >> A3;
	if(A1 + A2 + A3 != 180)
	{
		cout << "Error" << endl;
		return 0;
	}
	else if(A1 == A2 && A1 == A3)
	{
		cout << "Equilateral" << endl;
		return 0;
	}
	else if((A1 == A2 || A1 == A3 || A2 == A3) && (A1 != A2 || A3 != A2 || A1 != A3))
	{
		cout << "Isosceles" << endl;
		return 0;
	}
	else if(A1 != A2 && A3 != A2 && A1 != A3)
	{
		cout << "Scalene" << endl;
		return 0;
	}
}