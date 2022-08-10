#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	float l, h;
	cin>>l>>h;
	cout<<ceil(((l * l) * h)/3)<<endl;
	return 0;
}