#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, x = 0;
	float p, s, f;
	vector<float> a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> f;
		a.insert(a.end(), f);
	}
	while (x!=77) {
		cin >> x;
		if (x == 99) {
			cin >> s;
			cin >> p;
			a.insert(a.begin() + s, a[s-1] * ((100.0 - p) / 100.0));
			a[s-1] = a[s-1] / (100.0 / p);
		}
		if (x == 88) {
			cin >> s;
			a[s - 1] += a[s];
			a.erase(a.begin() + s);
		}
	}
	for (auto i = a.begin(); i != a.end(); ++i)
		cout << *i<<" ";
}