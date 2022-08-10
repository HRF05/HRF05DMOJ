#include <iostream>
#include <queue>
#include <climits>
using namespace std;
#define max 999999
#define endl "\n"
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0;
    cin >> n;
    if (!(n % 4)) ans++;
    while (n > 0) {
        if (!(n % 5))
            ans++;
        n -= 4;
    }
    cout << ans << endl;
}