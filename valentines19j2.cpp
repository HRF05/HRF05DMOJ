#include <iostream>
using namespace std;

int main(){
	int n, r, g, b, s = 0;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>r>>g>>b;
		if((r >= 240 && r <= 255) && (g >= 0 && g <= 200) && (b >= 95 && b <= 220)){
			s++;
		}
	}
	cout<<s<<endl;
}