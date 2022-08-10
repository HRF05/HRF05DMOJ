#include <iostream>
#include <vector>
using namespace std;
int V;

struct two {
    int a, b;
};
vector<two> fb;
vector<vector<two>> g;
int dist[5001];
bool vis[5001];
int findsmallest() {
    int l = 999999999, li = 999999999;
    for (int i = 0; i <= V; i++)
        if (!vis[i] && dist[i] <= l) {
            l = dist[i], li = i;
        }
    return li;
}
void dijsktras(int s, int e) {
    int ans = 0;
    for (int i = 0; i <= V; i++) {
        dist[i] = 999999999;
        vis[i] = false;

    }
    dist[s] = 0;
    for (int i = 0; i <= V; i++) {
        int u = findsmallest();
        vis[u] = true;
        for (auto y : g[u]) {
            int to = y.a, weight = y.b;
            if (dist[u] + weight < dist[to])
                dist[to] = dist[u] + weight;
        }
    }
    int low = 999999999;
    for (two i : fb) {
        if (dist[i.a] + i.b < low) {
            low = dist[i.a] + i.b;
        }
    }
    cout << low << endl;
}
int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int n, K;
    cin >> V >> n;
    g = vector<vector<two>>(V + 1);
    for (int i = 0; i < n; i++) {
        two q;
        int a, b, w;
        cin >> a >> b >> w;
        q.a = b, q.b = w;
        g[a].push_back(q);
        q.a = a, q.b = w;
        g[b].push_back(q);
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        two T;
        cin >> T.a >> T.b;
        fb.push_back(T);
    }
    int a = 0, b = V;
    cin >> a;
    dijsktras(a, b);
}