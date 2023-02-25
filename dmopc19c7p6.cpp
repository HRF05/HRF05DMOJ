#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#include <bits/stdc++.h>
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
const int MAX = 3e5 + 5;
int n, k, pn[MAX], lvl[MAX], dist[MAX][20], near[MAX], he[MAX], pr[MAX][20], sz[MAX];
vector<int> adj[MAX], lcp[MAX], over[MAX];
bool vis[MAX];

void gsz(int nd, int pr){
    sz[nd] = 1;
    for(auto ed : adj[nd]){
        if(ed == pr || vis[ed]) continue;
        gsz(ed, nd); sz[nd] += sz[ed];
    }
}
int cent(int nd, int pr, int s){
    for(auto ed : adj[nd]){
        if(ed == pr || vis[ed] || sz[ed]*2 <= s) continue;
        return cent(ed, nd, s);
    }
    return nd;
}
void dfs(int nd, int pr, int de){
    dist[nd][de] = dist[pr][de]+1;
    for(auto ed : adj[nd]){
        if(ed == pr || vis[ed]) continue;
        dfs(ed, nd, de);
    }
}
void cen(int s, int pr, int dep){
    gsz(s, -1); int nd = cent(s, -1, sz[s]); vis[nd] = 1; pn[nd] = pr; lvl[nd] = dep;
    dist[nd][dep] = 0; over[nd].resize(sz[s]+1); lcp[nd].resize(sz[s]);
    for(auto ed : adj[nd]){
        if(vis[ed]) continue;
        dfs(ed, nd, dep);
    }
    for(auto ed : adj[nd]){
        if(vis[ed]) continue;
        cen(ed, nd, dep + 1);
    }
}
void update(int x, int val){
    for(int i = x, pre = -1, tp; i != -1; pre = i, i = pn[i]){
        tp = val - dist[x][lvl[i]];
        if(tp < 0) continue;
        lcp[i][min(tp, (int)lcp[i].size()-1)]++;
        if(pre != -1) over[pre][min(tp, (int)over[pre].size()-1)]++;
    }
}
int query(int x){
    int ret = 0;
    for(int i = x, pre = -1; i != -1; pre = i, i = pn[i]){
        if(dist[x][lvl[i]] < lcp[i].size()) ret += lcp[i][dist[x][lvl[i]]];
        if(pre != -1 && dist[x][lvl[i]] < over[pre].size()) ret -= over[pre][dist[x][lvl[i]]];
    }
    return ret;
}
void dfsc(int nd, int prn){
    pr[nd][0] = prn;
    he[nd] = he[prn] + 1;
    for(int i = 1; i < 20; i++) pr[nd][i] = pr[pr[nd][i-1]][i-1];
    for(auto ed : adj[nd]){
        if(ed == prn) continue;
        dfsc(ed, nd);
    }
}
int lca(int a, int b){
    if(he[a] < he[b]) swap(a, b);
    int height = he[a] - he[b];
    for(int i = 0; i < 20; i++){
        if(height & (1<<i)) a = pr[a][i];
    }
    if(a == b) return a;
    for(int i = 19; i >= 0; i--){
        if(pr[a][i] != pr[b][i] && pr[a][i] && pr[b][i]) a = pr[a][i], b = pr[b][i];
    }
    return pr[a][0];
}
int distt(int a, int b){
    return he[a] + he[b] - 2 * he[lca(a, b)];
}
void dfsb(int nd, int pr, bool T){
    for(auto ed : adj[nd]){
        if(ed == pr) continue;
        if(T) near[ed] = min(near[ed], near[nd]+1);
        dfsb(ed, nd, T);
        if(!T) near[nd] = min(near[nd], near[ed]+1);
    }
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>k; near[n] = n-1;
    for(int i = 1, a, b; i < n; i++){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
        near[i] = n-1;
    }
    for(int i = 0, a; i < k; i++){
        cin>>a; near[a] = 0;
    }
    for(int i = 0; i < 20; i++){
        for(int y = 0; y <= n; y++) dist[y][i] = -1;
    }
    dfsb(1, -1, 0); dfsb(1, -1, 1); cen(1, -1, 0); dfsc(1, 0);
    for(int i = 1, f, p; i <= n; i++){
        cin>>f>>p;
        int d = distt(i, f);
        if(d > near[i] + p) update(i, near[i]);
        else update(i, d-p-1);
    }
    
    for(int i = 1; i <= n; i++){
        for(int y = lcp[i].size()-2; y >= 0; y--) lcp[i][y] += lcp[i][y+1];
        for(int y = over[i].size()-2; y >= 0; y--) over[i][y] += over[i][y+1];
    }
    for(int i = 1; i <= n; i++) cout<<query(i)<<" ";
}