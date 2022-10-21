#include <iostream>
using namespace std;

int a, b, c, d = 0;
int main(){
	cin>>a>>b;
	for(int i = 0; i < b; i++){
		cin>>c;
		d += c >= a;
	}
	cout<<d<<endl;
}