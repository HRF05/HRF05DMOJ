#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int c;
	double y, x=0;
	cin>>c;
	for(int i = 1; i <= c; i++){
		cin>>y;
		x = x + y;
	}
	double a = x / c;
	cout<<fixed<<setprecision(1)<<a<<endl;
	return 0;
}
