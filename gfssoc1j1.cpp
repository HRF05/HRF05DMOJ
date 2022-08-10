#include <iostream>
using namespace std;

int main(){
	int a, b, c[202], d = 0;
	cin>>a;
	cin>>b;
	for(int i = 0; i < b; i++){
		cin>>c[i];
		if(c[i] >= a){
			d = d + 1;
		}
	}
	cout<<d<<endl;
}