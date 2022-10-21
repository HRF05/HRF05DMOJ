#include <iostream>
using namespace std;

int main(){
	int n;
	long double a, b, c;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a>>b>>c;
		if(a * b != c) cout<<"16 BIT S/W ONLY"<<endl;
		else cout<<"POSSIBLE DOUBLE SIGMA"<<endl;
	}
}