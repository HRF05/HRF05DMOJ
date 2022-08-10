#include <iostream>
using namespace std;

int main(){
	int n, a, b, m = 0;
	cin>>n;
	for (int i = 0; i < n; i++){
		cin>>a>>b;
		m = max(m, b - a);
	}
	cout<<m<<endl;
}
