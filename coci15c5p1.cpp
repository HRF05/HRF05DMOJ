#include <iostream>
using namespace std;

int main(){
	int l, d, x, digits = 0;
	cin>>l;
	cin>>d;
	cin>>x;
	for(int i = l; i <= d; i++){
		for(int y = 1; y < 10001; ){
			int z = (i / y) % 10;
			digits = digits + z;
			y = y * 10;
			
		}
		if(digits == x){
			cout<<i<<endl;
			i = d;
		}
		digits = 0;
	}
	for(int i = d; i >= l; i--){
		for(int y = 1; y < 10001; ){
			int z = (i / y) % 10;
			digits = digits + z;
			y = y * 10;
			
		}
		if(digits == x){
			cout<<i<<endl;
			return 0;
		}
		digits = 0;
	}
}