#include <iostream>
#include <cmath>
using namespace std;

int main(){
	double p, c, v;
	cin>>p>>c>>v;
	double p2 = ceil(p / 3), c2 = ceil(c / 3), v2 = ceil(v / 3);
	cout<<int(p2 + c2 + v2)<<endl;
}
