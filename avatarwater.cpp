#include <iostream>
using namespace std;

int main(){
	int a, b, c;
	cin>>a>>b>>c;
	if(a > b && a > c){
		cout<<a - b<<endl;
	}
	else if(b > a && b > c){
		cout<<b - c<<endl;
	}
	else if(c > b && c > a){
		cout<<c - a<<endl;
	}
}