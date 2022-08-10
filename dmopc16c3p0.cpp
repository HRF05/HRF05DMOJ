#include <iostream>
using namespace std;

int main(){
	double VI, RA, RB;
	cin>>VI>>RA>>RB;
	cout << VI * (1 +(RA / RB)) << endl;
}