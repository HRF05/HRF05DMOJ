#include <iostream>
using namespace std;

int main()
{
	int n, a, t = 0, h = 0, x = 0;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a;
		t += a;
		if(h == 0 && t > 9){
			x = x + 1;
		}
		if(t > 9){
			h = 1;
		}
		else{
			h = 0;
		}
	}
	cout<<x<<endl;
}
