#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
	int v;
	cin>>v;
	float g = -9.8;
	double tB = (-v - sqrt(pow(v, 2) - (4 * (g / 2)) * (0))) / g;
	cout<<fixed<<setprecision(6)<<tB<<endl;
	return 0;
}