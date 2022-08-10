#include <iostream>
using namespace std;

int main(){
	int a, b, n, l;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a;
		cin >> b;
		if (b > a){
			l = (a - 1) * 2;
		}
		else if (a > b){
			l = (b - 1) * 2;
		}
		else{
			l = (a - 1)* 2;
		}
		cout << l << endl;
	}
}