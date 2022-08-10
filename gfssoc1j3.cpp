#include <iostream>
using namespace std;
int main(){
	int h, m, s, hA, mA, sA;
	double sT, sTa, sTb;
	char nothing, nothing2, nothing3, nothing4;
	
	cin>>h>>nothing>>m>>nothing2>>s>>hA>>nothing3>>mA>>nothing4>>sA;
	sTa = sA + (mA * 60) + (hA * 60 * 60);
	sT = s + (m * 60) + (h * 60 * 60);
	sTb = (sT - sTa) * -1;
	cout<<sTb<<endl;
}
