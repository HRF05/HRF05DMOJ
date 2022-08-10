#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long a, b, c;
	cin>>a>>b>>c;
	long long ca = acos(((pow(a, 2) + pow(b, 2)) - pow(c, 2)) / (2 * a * b)), ba = acos((pow(a, 2) + pow(c, 2) - pow(b, 2)) / (2 * a * b)), aa = 180 - (ba + ca);
	if((a >= b + c || c >= b + a || b >= a + c) || (a == 0 || b == 0 || c == 0)){
		cout<<"Maybe I should go out to sea..."<<endl;
		return 0;
	}
	else if(ca + ba + aa != 180){
		cout<<"Maybe I should go out to sea..."<<endl;
	}
	else if(ca + ba + aa == 180){
		cout<<"Huh? A triangle?"<<endl;
	}
}