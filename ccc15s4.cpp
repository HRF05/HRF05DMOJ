#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int V, h;
struct tri {
    int a, b, c;
};
vector<vector<tri>> g;
int dist[2001][201];
void dijsktras(int s, int e) {
    queue<pair<int, int>> q;
    for (int i = 0; i < V; i++) {
        for (int y = 0; y < h; y++)  dist[i][y] = INT_MAX;
    }
    dist[s][0] = 0;
    pair<int, int> p;
    p.first = s, p.second = 0;
    q.push(p);
    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();
        for (auto y : g[u.first]) {
            int to = y.a, weight = y.b, damage = y.c;
            if (u.second + damage < h && dist[u.first][u.second] + weight < dist[to][u.second + damage]) {
                dist[to][u.second + damage] = dist[u.first][u.second] + weight;
                p.first = to;
                p.second = u.second + damage;
                q.push(p);
            }
        }
    }
    int low = INT_MAX;
    for (int i = 0; i < h; i++)
        if (dist[e][i] < low) low = dist[e][i];

    if (low == INT_MAX)
        cout << -1 << endl;
    else
        cout << low << endl;
}
int main() {
    int n;
    cin >> h >> V >> n;
    g = vector<vector<tri>>(V);
    for (int i = 0; i < n; i++) {
        int a, b, w, d;
        cin >> a >> b >> w >> d;
        tri q;
        q.a = b - 1, q.b = w, q.c = d;
        g[a - 1].push_back(q);
        q.a = a - 1, q.b = w, q.c = d;
        g[b - 1].push_back(q);
    }
    int a, b;
    cin >> a >> b;
    dijsktras(a - 1, b - 1);
}