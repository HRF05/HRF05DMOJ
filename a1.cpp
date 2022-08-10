#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, a;
	string b;
	cin>>n;
	for (int i = 0; i < n; i++) {
		cin>>a;
		getline(cin, b);
		cout<<i + 1<<" ";
		for (int y = 1; y < b.length(); y++){
			if (y != a){
				cout<<b[y];
			}
		}
		cout<<endl;
	}
}