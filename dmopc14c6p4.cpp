#include <iostream>
using namespace std;

int main() {
	int n, m, h, t[1000], b = 0;
	cin>>n>>m>>h;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	for (int i = n - 1; i > 0; i--) {
		if (t[i] - t[i - 1] > h) {
			int d = t[i] - t[i - 1];
			int k = 0;
			while (d > h) {
				d -= m;
				k++;
			}
			t[i - 1] += k * m;
			b += k;
		}
	}
	cout<<b<<endl;
}