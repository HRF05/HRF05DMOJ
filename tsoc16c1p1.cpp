#include <iostream>
using namespace std;

int main(){
	int n, l, a, b, f;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>l>>a>>b>>f;
		if(l - a >= f && l - b <= f){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
}