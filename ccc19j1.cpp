#include <iostream>
using namespace std;
int main()
{
	int A3;
	int A2;
	int A1;
	int B3;
	int B2;
	int B1;
	int Ap;
	int Bp;
	cin >> A3;
	cin >> A2;
	cin >> A1;
	cin >> B3;
	cin >> B2;
	cin >> B1;
	Ap = (A3 * 3) + (A2 * 2) + A1;
	Bp = (B3 * 3) + (B2 * 2) + B1;
	if(Ap > Bp)
	cout << "A" << endl;
	else if(Bp > Ap)
	cout << "B" << endl;
	else if(Bp == Ap)
	cout << "T" << endl;
}
