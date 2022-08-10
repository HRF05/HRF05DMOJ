#include <iostream>
#include <vector>
using namespace std;
int V, t;
vector<int> fb;
struct two {
    int a, b;
};
vector<vector<two>> g;
int dist[2001];
bool vis[2001];
int findsmallest() {
    int l = 999999999, li = 999999999;
    for(int i = 0; i <= V; i++)
        if(!vis[i] && dist[i] <= l){
            l = dist[i], li = i;
        }
    return li;
}
void dijsktras(int s, int e) {
    int ans = 0;
    for(int i = 0; i <= V; i++){
        dist[i] = 999999999;
        vis[i] = false;

    }
    dist[s] = 0;
    for(int i = 0; i <= V; i++){
        int u = findsmallest();
        vis[u] = true;
        for(auto y : g[u]){
            int to = y.a, weight = y.b;
            if (dist[u] + weight < dist[to])
                dist[to] = dist[u] + weight;
        }
    }
    for(int i: fb){
        if(dist[i] <= t){
            ans++;
        }
    }
    cout<<ans<<endl;
}
int main() {
    int n, K;
    cin>>t>>V>>n>>K;
    for (int i = 0, a; i < K; i++) {
        cin>>a;
        fb.push_back(a);
    }
    g = vector<vector<two>>(V + 1);
    for (int i = 0; i < n; i++) {
        two q;
        int a, b, w;
        cin>>a>>b>>w;
        q.a = b, q.b = w;
        g[a].push_back(q);
    }
    int a = 0, b = V;
    dijsktras(a, b);
}