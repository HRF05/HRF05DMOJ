#include <iostream>
using namespace std;

int main(){
	float n, s = 0;
	int T, i, k;
	string na[1000];
	cin >> k;
	for (i = 0; i < k; i++){
		cin>>na[i];
		cin>>n;
		if (n > s){
			s = n;T = i;
		}
	}
	cout << na[T] << endl;
}
