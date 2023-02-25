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
struct tri {ll first, second, t;bool operator<(const tri& T){return t < T.t;}};
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
int n, m, sz[MAX], ar[MAX];
ll ans = 0;
vector<int> adj[MAX], fr;
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
        if(ed == pr || sz[ed]*2 <= s || vis[ed]) continue;
        return cent(ed, nd, s);
    }
    return nd;
}
void dfs(int nd, int pr, int w, int ln, bool T){
    for(auto ed : adj[nd]){
        if(ed == pr || vis[ed]) continue;
        dfs(ed, nd, w + ar[ed], ln + 1, T);
    }
    if(T) ans += lower_bound(fr.begin(), fr.end(), m*ln-w) - fr.begin() + (w < m*ln);
    else fr.pb(w-m*ln);
}
void cen(int s){
    gsz(s, -1);
    int nd = cent(s, -1, sz[s]); vis[nd] = 1; fr.clear();
    for(auto ed : adj[nd]){
        if(vis[ed]) continue;
        dfs(ed, nd, ar[ed] + ar[nd], 2, 1);
        dfs(ed, nd, ar[ed], 1, 0);
        sort(fr.begin(), fr.end());
    }
    for(auto ed : adj[nd]){
        if(!vis[ed]) cen(ed);
    }
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m; m++;
    for(int i = 1; i <= n; i++) cin>>ar[i];
    for(int i = 1, a, b; i < n; i++){
        cin>>a>>b;
        adj[a].pb(b); adj[b].pb(a);
    }
    cen(1);
    cout<<ans<<endl;
}