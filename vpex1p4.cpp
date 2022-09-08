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
const int MAX = 1e5 + 5, MX = 1e6 + 5;
ll n, q, dist[MAX], prnt[MAX][19], depth[MAX], dp[MX][2], pa[2];
vector<pll> adj[MAX];
void dfs(ll nd, ll parent){
    prnt[nd][0] = parent;
    
    for(int i = 1; i < 19; i++){
        prnt[nd][i] = prnt[prnt[nd][i-1]][i-1];
    }
    
    for(auto ed : adj[nd]){
        if(ed.f == parent) continue;
        dist[ed.f] = dist[nd] + ed.s;
        depth[ed.f] = depth[nd] + 1;
        dfs(ed.f, nd);
    }
    return;
    
}
ll lca(ll a, ll b){
    if(a == b) return b;
    if(depth[a] < depth[b]) swap(a, b);
    for(ll i = 18; i >= 0; i--){
        if(depth[prnt[a][i]] >= depth[b]) a = prnt[a][i];
    }
    if(a == b) return b;
    for(ll i = 18; i >= 0; i--){
        if(prnt[a][i] != prnt[b][i]) a = prnt[a][i], b = prnt[b][i];
    }
    return prnt[a][0];
}
ll distt(ll a, ll b){
    return dist[a] + dist[b] - 2 * dist[lca(a, b)];
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    for(ll i = 1, a, b, c; i < n; i++){
        cin>>a>>b>>c;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    dfs(1, 1);
    for(ll i = 0, a[2]; i < q; i++){
        cin>>a[0]>>a[1];
        ll t = distt(a[0], a[1]);
        for(int y = 0; y < 2; y++){
            dp[i][y] = min(dp[i-1][0] + distt(pa[0], a[1-y]) + t, dp[i-1][1] + distt(pa[1], a[1-y]) + t);
        }
        pa[0] = a[0]; pa[1] = a[1];
    }
    cout<<min(dp[q-1][0], dp[q-1][1])<<endl;
}