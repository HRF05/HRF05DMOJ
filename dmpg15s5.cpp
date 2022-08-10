#include <iostream>
using namespace std;
int main() {
    int n, m, ans = 0;
    short ps[10001][10001];
    cin>>n>>m;
    for(int i = 0; i <= n; i++)
        for(int y = 0; y <= n; y++) ps[i][y] = 0;

    for(int i = 0; i < m; i++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        ps[a][b] += 1;
        ps[a][b + d] -= 1;
        ps[a + c][b] -= 1;
        ps[a + c][b + d] += 1;
    }
    for(int i = 0; i <= n; i++)
        for(int y = 0; y <= n; y++){
            if(i) ps[i][y] += ps[i-1][y];
            if(y) ps[i][y] += ps[i][y-1];
            if(i && y) ps[i][y] -= ps[i-1][y-1];
            if (ps[i][y] % 2) ans++;
        }
    cout<<ans<<endl;
}