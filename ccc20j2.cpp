#include <iostream>
using namespace std;
int p, n, r, t;
int main(){
	cin>>p>>n>>r;
	t = n;
	for(int i = 0; n <= p; i++){
		t *= r;
		n += t;
		if(n > p) cout<<i + 1<<endl;
	}
}