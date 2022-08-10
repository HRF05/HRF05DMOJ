#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int main() {
	long long a[10000000]{ 0 }, l, u, t = 0;
	cin >> l >> u;
	a[1] = 1;
	for (int i = 2; i <= sqrt(u); i++)
		for (int y = i * i; y <= u; y += i) {
			a[y] += i;
			if(y / i != i) a[y] += y / i;
		}
	for (int i = l; i <= u; i++)
		t += abs(i - a[i] - 1);
	cout << t << endl;
}