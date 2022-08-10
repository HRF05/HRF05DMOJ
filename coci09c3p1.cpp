#include <iostream>
using namespace std;

int main(){
	int a, b;
	cin>>a>>b;
	int A3 = (a / 100) % 10, A2 = (a / 10) % 10, A1 = a % 10;
	int B3 = (b / 100) % 10, B2 = (b / 10) % 10, B1 = b % 10;
	int AReversed = A1 * 100 + A2 * 10 + A3, BReversed = B1 * 100 + B2 * 10 + B3;
	if(BReversed > AReversed){
		cout << BReversed << endl;
	}
	else{
		cout << AReversed << endl;
	}
}