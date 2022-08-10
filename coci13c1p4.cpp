#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
#include <complex>
#include <string>
using namespace std;
int main() {
	int n, k;
	long long ans = 0;
	cin >> n >> k;
	vector<pair<int, int>> j;
	pair<int, int> t;
	for (int i = 0; i < n; i++) {
		cin >> t.second >> t.first;
		j.push_back(t);
	}
	sort(j.begin(), j.end());
	multiset<int> c;
	int te;
	for (int i = 0; i < k; i++) {
		cin >> te;
		c.insert(te);
	}
	for (int i = j.size() - 1; i >= 0; i--) {
		auto a = c.lower_bound(j[i].second);
		if (a != c.end()) {
			ans += j[i].first;
			c.erase(a);
		}
	}
	cout << ans << endl;
}