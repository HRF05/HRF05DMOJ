#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long double K, N;
	cin>>N;
	cin>>K;
	long long x = N - floor((N / (K + 1)));
	cout<<x<<endl;
}