#include <iostream>
#include <queue>
#include <climits>
using namespace std;
#define max 999999
#define endl "\n"
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int V, n, dist[1001], a, b, k, g, GEORGE[1001];
    pair<int, int> adj[1001][1001];
    bool vis[1001][1001];
    queue<int> q;
    cin >> V >> n >> a >> b >> k >> g;
    for (int i = 0; i <= V; i++) {
        dist[i] = max;
        for (int y = 0; y <= V; y++)
            adj[i][y].first = max;
    }
    for (int i = 0; i < g; i++)
        cin >> GEORGE[i];
    for (int i = 0; i < n; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        adj[A][B].first = C;
        adj[B][A].first = C;
    }
    int T = -k;
    for (int i = 1; i < g; i++) {
        adj[GEORGE[i]][GEORGE[i-1]].second = T ;
        adj[GEORGE[i-1]][GEORGE[i]].second = T;
        vis[GEORGE[i]][GEORGE[i - 1]] = false;
        vis[GEORGE[i - 1]][GEORGE[i]] = false;
        T += adj[GEORGE[i - 1]][GEORGE[i]].first;
    }
    dist[a] = 0;
    q.emplace(a);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int y = 1; y <= V; y++) {
            int weight = adj[u][y].first;
            if (!vis[u][y] && adj[u][y].second < dist[u] && adj[u][y].second + weight > dist[u]) {
                weight += (weight - (dist[u] - adj[u][y].second));
            }
            if (weight + dist[u] < dist[y]) {
                dist[y] = weight + dist[u];
                q.emplace(y);
            }
        }
        
    }
    cout << dist[b] << endl;
}