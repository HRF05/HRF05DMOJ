#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, a[50000], b[50000];
	long t = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(a, a+n);
    sort(b, b+n, greater<int>());
	for (int i = 0; i < n; i++) {
		t += a[i] * b[i];
	}
	cout << t;
}