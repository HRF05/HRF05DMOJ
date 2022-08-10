#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
int V, h;
struct two{
    int a, b;
};
int g[3001][3001];
two C[3001];
int dist[3001];
bool vis[3001];
int findsmallest(){
    int l = 1e18, li;
    for(short i = 0; i < V; i++)
        if (!vis[i] && dist[i] <= l){
            l = dist[i], li = i;
        }
    return li;
}
void dijsktras(int s, int e){
    for(short i = 0; i < V; i++){
        dist[i] = 1e18;
        vis[i] = false;

    }
    dist[s] = 0;
    for(short i = 0; i < V; i++){
            short u = findsmallest();
            vis[u] = true;
            int C = 0;
            for(auto y : g[u]) {
                int to = C, weight = y;
                if (dist[u] + weight < dist[to])
                    dist[to] = dist[u] + weight;
                C++;
            }
    }
    sort(dist, dist + V);
    int Q;
    cin>>Q;
    for(int i = 0; i < Q; i++){
      int t;
      cin>>t;
      cout<<upper_bound(dist, dist+V, t) - dist<<endl;
    }
}
signed main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> V;
    for (int i = 0; i < V; i++){
      cin >> C[i].a >> C[i].b;
    }
    for(int i = 0; i < V; i++){
        int a = i;
        for(int y = i + 1; y < V; y++){
            int b = y;
        int B = (abs(C[a].a - C[b].a) * abs(C[a].a - C[b].a)) + ((abs(C[a].b - C[b].b)) * (abs(C[a].b - C[b].b)));
        g[a][b] = B;
        g[b][a] = B;
        }
    }
    int X;
    cin>>X;
    int a = X, b = V;
    dijsktras(a - 1, b - 1);
}