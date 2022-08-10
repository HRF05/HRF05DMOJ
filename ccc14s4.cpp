#include <iostream>
#include <set>
#include <vector>
#define endl "\n"
using namespace std;
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    set<int> sx;
    set<int> sy;
    int ps[2001][2001], n, t;
    cin >> n >> t;
    int a[1001], b[1001], c[1001], d[1001], e[1001];
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i] >> e[i];
        sx.insert(a[i]);
        sx.insert(c[i]);
        sy.insert(b[i]);
        sy.insert(d[i]);
    }
    vector<int> vx(sx.begin(), sx.end());
    vector<int> vy(sy.begin(), sy.end());
    for (int i = 0; i <= sx.size(); i++) {
        for (int y = 0; y <= sy.size(); y++) {
            ps[i][y] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        int at = lower_bound(vx.begin(), vx.end(), a[i]) - vx.begin();
        int bt = lower_bound(vy.begin(), vy.end(), b[i]) - vy.begin();
        int ct = lower_bound(vx.begin(), vx.end(), c[i]) - vx.begin();
        int dt = lower_bound(vy.begin(), vy.end(), d[i]) - vy.begin();
        int et = e[i];
        ps[at][bt] += et;
        ps[ct][bt] -= et;
        ps[at][dt] -= et;
        ps[ct][dt] += et;
    }
    for (int i = 0; i <= sx.size(); i++) {
        for (int y = 0; y <= sy.size(); y++) {
            if(i) ps[i][y] += ps[i-1][y];
            if(y) ps[i][y] += ps[i][y-1];
            if(i && y) ps[i][y] -= ps[i-1][y-1];
            if (ps[i][y] >= t) ans += (long long)(vx[i + 1] - vx[i]) * (long long)(vy[y + 1] - vy[y]);
        }
    }
    cout << ans << endl;
    return 0;
}