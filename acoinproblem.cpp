#include <iostream>
#include <algorithm>
using namespace std;
struct tri{
    int a, b, c;
    bool operator<(const tri& t){
        return a < t.a;
    }
};
int main() { // 10000
    cin.sync_with_stdio(0); cin.tie(0);
    int n, v, c[2000], p[10001], C = 0, ans[100000], L = 0;
    tri q[100000];
    cin>>n>>v;
    for(int i = 0; i < n; i++)
        cin >> c[i];
    for(int i = 0; i < v; i++){
        cin >> q[i].b >> q[i].a;
        q[i].c = i;
        if (q[i].b > L) L = q[i].b;
    }
    for(int i = 0; i <= L; i++)
        p[i] = 10001;
    sort(q, q + v);
    q[v].a = -1;
    p[0] = 0;
    for(int i = 0; i < n; i++){
        for(int y = c[i]; y <= L; y++){
            p[y] = min(p[y - c[i]] + 1, p[y]);
        }
        for(; q[C].a == i + 1; C++){
            if (10001 == p[q[C].b])
                ans[q[C].c] = -1;
            else
                ans[q[C].c] = p[q[C].b];
        }
    }
    for(int i = 0; i < v; i++)
        cout << ans[i] << endl;
}