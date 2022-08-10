#include <iostream>
using namespace std;
#define endl "\n"
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int w, h, n, q;
    long long cake[5001][5001];
    cin >> w >> h >> n;
    for (int i = 0; i <= w + 1; i++)
        for (int y = 0; y <= h + 1; y++) cake[i][y] = 0;

    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cake[a][b] += 1;
        cake[a][d + 1] -= 1;
        cake[c + 1][b] -= 1;
        cake[c + 1][d + 1] += 1;
    }
    for (int i = 0; i <= w + 1; i++)
        for (int y = 0; y <= h + 1; y++) {
            if (i) cake[i][y] += cake[i - 1][y];
            if (y) cake[i][y] += cake[i][y - 1];
            if (i && y) cake[i][y] -= cake[i - 1][y - 1];
        }
    for (int i = 0; i <= w + 1; i++)
        for (int y = 0; y <= h + 1; y++) {
            if (i) cake[i][y] += cake[i - 1][y];
            if (y) cake[i][y] += cake[i][y - 1];
            if (i && y) cake[i][y] -= cake[i - 1][y - 1];
        }
        
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << cake[c][d] + cake[a-1][b-1] - cake[c][b-1] - cake[a-1][d] << endl;
    }
}