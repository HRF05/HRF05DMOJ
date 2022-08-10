#include <iostream>
#include <algorithm>
using namespace std;
int main() { // 500001
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, a[500001], b[500001];
    pair<long long, long long> m[661][661];
    int as[661], bs[661];
    int az[661], bz[661];
    cin >> n;
    for (int i = 0; i <= 660; i++)
        for (int y = 0; y <= 660; y++) m[i][y].first = 0, m[i][y].second = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if(a[i] == 0){
            az[b[i]]++;
        }
        if(b[i] == 0){
            bz[a[i]]++;
        }
        m[0][0].first += 1;
        m[a[i]][0].first -= 1;
        m[0][b[i]].first -= 1;
        m[a[i]][b[i]].first += 1;
        m[a[i] + 1][b[i] + 1].second += 1;
        m[a[i] + 1][660].second -= 1;
        m[660][b[i] + 1].second -= 1;
        m[660][660].second += 1;
    }
    for (int i = 0; i <= 660; i++)
        for (int y = 0; y <= 660; y++) {
            if (i) m[i][y].first += m[i - 1][y].first, m[i][y].second += m[i - 1][y].second;
            if (y) m[i][y].first += m[i][y - 1].first, m[i][y].second += m[i][y - 1].second;
            if (i && y) m[i][y].first -= m[i - 1][y - 1].first, m[i][y].second -= m[i - 1][y - 1].second;
        }
  cout<<endl<<endl<<endl;
    for (int i = 0; i < n; i++) {
      int N = 0, M = 0;
        if(a[i] == 650){
          M+=az[b[i]];
        }
        if(b[i] == 650){
          M+=bz[a[i]];
        }
      
      cout << m[a[i]][b[i]].first + 1 - N << " " << n - m[a[i]][b[i]].second - M << "\n";
    }
}