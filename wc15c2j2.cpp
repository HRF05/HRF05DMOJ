#include <iostream>
using namespace std;

int main(){
	int y, x, w, t = 0;
	cin>>y>>x;
	for(int i = 0; i < y; i++){
		cin>>w;
		if(w <= x){
			t += w;
		}
	}
	cout<<t<<endl;
}