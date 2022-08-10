#include <iostream>
#include <queue>
#include <climits>
using namespace std;
#define max 999999
#define endl "\n"
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, a[100000], b[100000], k = -1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i) a[i] += a[i - 1];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (i) b[i] += b[i - 1];
        if (a[i] == b[i])
            k = i;
    }
    cout << k + 1 << endl;
}