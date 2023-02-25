#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#include <bits/stdc++.h>
#include <queue>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long long unsigned llu;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
struct tri {int first, second, t;bool operator<(const tri& T){return first < T.first;}};
#define f first
#define s second
#define pb push_back
#define pf push_front
#define mp make_pair
#define INF 2e18
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
const int MAX = 1e5 + 5;
int n, in[MAX], cnt = 0, pr[MAX][17], dist[MAX], sz[MAX], adj[MAX];
pii id[MAX];
void dfs(int nd, int prnt){
    sz[nd] = 1; pr[nd][0] = prnt;
    if(nd){
        in[nd] = ++cnt; dist[nd] = dist[prnt]+1;
        for(int i = 1; i < 17; i++){
            if(pr[pr[nd][i-1]][i-1] == -1) break;
            pr[nd][i] = pr[pr[nd][i-1]][i-1];
        }
    }
    for(int i = id[nd].f; i < id[nd].s; i++){
        dfs(adj[i], nd); sz[nd] += sz[adj[i]];
    }
    cnt++;
}
int jump(int start, int height){
    for(int i = 0; i < 17; i++){
        if((height>>i)&1) start = pr[start][i];
    }
    return start;
}
int lca(int u, int v){
    if(dist[u] < dist[v]) swap(u, v);
    u = jump(u, dist[u] - dist[v]);
    if(u == v) return u;
    for(int i = 16; i >= 0; i--){
        if(pr[u][i] != pr[v][i]){u = pr[u][i]; v = pr[v][i];}
    }
    return pr[u][0];
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 0, a, y = 0; i < n; adj[i]--, i++, y += a){
        cin>>a;
        id[i] = {y, y+a};
        for(int j = y; j < id[i].s; j++) cin>>adj[j];
    }
    dfs(0, -1);
    int qu; cin>>qu;
    while(qu--){
        int u, v; cin>>u>>v; u--;v--;
        int x = lca(u, v);
        if(in[u] == in[v]) cout<<0<<endl;
        else if(in[u] < in[v]) cout<<in[v] - in[x] - dist[u] + dist[x]<<endl;
        else cout<<sz[jump(u, dist[u]-dist[x]-1)]*2 + in[v] - in[x] - dist[u] + dist[x]<<endl;
  }
}