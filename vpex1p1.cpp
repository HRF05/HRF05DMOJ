#include <iostream>
using namespace std;

int main(){
	int x, c = 0, z = 101, k;
	for(int i = 0; i < 2; i++){
		for(int y = 0; y < 5; y++){
			cin>>x;
			c += x;
			if(x < z) z = x;
		}
		c -= z;
		z = 101;
		if(i == 0){
			k = c;
			c = 0;
		}
		else{
			if(k > c) cout<<k<<endl;
			else cout<<c<<endl;
		}

	}
}