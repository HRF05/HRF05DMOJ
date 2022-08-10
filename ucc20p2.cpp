#include <iostream>
using namespace std;

int main(){
	int a, b, mi = INT_MAX, n;
	cin>>n;
	for(int i = 0, c = 0; i < n; i++){
		cin>>a;
		for(int y = 0; y < a; y++){
			cin>>b;
			c += b;
		}
		mi = min(mi, c);
	}
	cout<<mi<<endl;
}