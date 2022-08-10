#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main(){
	int n, a, b, r, t, c, f;
	cin>>n;
	for(int i = 0; i < n; i++){
		r = 0;
		f = 0;
		cin>>a>>b;
		for(int y = 1; y <= a; y *= 10)
			t = y;
		for(int y = 1; y <= t; y *= 10){
			c = (a / y) % 10;
			if(c != 0)
				r += c * (t / y);
		}
		for(int y = 1; y <= b; y *= 10)
			t = y;
		for(int y = 1; y <= t; y *= 10){
			c = (b / y) % 10;
			if(c != 0)
				r += c * (t / y);
		}	
		for(int y = 1; y <= r; y *= 10)
			t = y;
		for(int y = 1; y <= t; y *= 10){
			c = (r / y) % 10;
			if(c != 0)
				f += c * (t / y);
		}
		cout<<f<<endl;
	}
}