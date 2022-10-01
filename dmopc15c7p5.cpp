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
int n, in[MAX], out[MAX], cnt = 0, qu, u, v, pr[MAX][20], dist[MAX];
vector<int> adj[MAX];
void dfs(int nd, int prnt){
    in[nd] = ++cnt;
    dist[nd] = dist[prnt]+1;
    pr[nd][0] = prnt;
    for(int i = 1; i < 20; i++) pr[nd][i] = pr[pr[nd][i-1]][i-1];
    for(auto ed : adj[nd]){
        dfs(ed, nd);
    }
    out[nd] = cnt++;
}
bool isAnc(int u, int v){
    return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v){
    if(isAnc(u, v)) return u;
    if(isAnc(v, u)) return v;
    for(int i = 19; i >= 0; i--){
        if(isAnc(pr[u][i], v)) u = pr[u][i];
    }
    return pr[u][0];
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 0, a, nd; i < n; i++){
        cin>>a;
        while(a--){
            cin>>nd;
            adj[i].pb(--nd);
        }
    }
    dfs(0, 0);
    cin>>qu;
    while(qu--){
        cin>>u>>v; u--;v--;
        if(in[u] < in[v]){
            int x = lca(u, v);
            cout<<in[v] - in[x] - dist[u] + dist[x]<<endl;
        }
        else{
            int x = lca(v, u);
            cout<<out[x] - out[u] - dist[u] + dist[x]<<endl;
        }
  }
}