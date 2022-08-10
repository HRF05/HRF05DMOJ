#include <iostream>
using namespace std;

int main(){
	int a, b, c;
	cin>>a>>b>>c;
	for(int i; i < c; i++){
		a *= b;
	}
	cout<<a<<endl;
}