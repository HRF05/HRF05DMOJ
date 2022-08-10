#include <iostream>
using namespace std;

int main(){
	double N, D, Q;
	int L, T;
	cin>>N>>D>>Q>>L>>T;
	cout<<double((N * 5) + (D * 10) + (Q * 25) + (L * 100) + (T * 200))<<endl;
}