#include <iostream>

using namespace std;

int main(){
	int l;
	string x;
	cin>>l>>x;
	for (int i = 0; i < l - 1; i++){
		int a = x[i], b = x[i + 1];
		if (a < b){
			int t = x[i];
			x[i] = x[i + 1];
			x[i + 1] = t;
			break;
		}
	}
	cout<<x<<endl;
}
