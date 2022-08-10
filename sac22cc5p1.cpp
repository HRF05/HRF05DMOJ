#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n, c;
	cin>>n>>c;
	for (int i = 0, t; i < n; i++) {
		cin>>t;
		cout<<t + (c * 2)<<" ";
	}
}