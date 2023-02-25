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
const int MAX = 2e5 + 5;
int n, k, sz[MAX], ans = 2, c[MAX], bit[MAX], other, pre;
bool vis[MAX];
vector<int> adj[MAX];
void update(int x, int val, int u){
    for(; x <= u; x += x&-x) bit[x] = max(bit[x], val);
}
int query(int x){
    int ret = 0;
    for(; x; x -= x&-x) ret = max(ret, bit[x]);
    return ret;
}
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
void dfs(int nd, int pr, int pr2, int dis, int cur, int L, bool B, bool T){
    if(!pr2 || c[nd] == c[pr2]) cur++;
    else cur = 2, B = 0;
    if(cur >= k) return;
    if(B) L = cur;
    if(T){
      pre = max(pre, dis);
      ans = max(ans, dis + query(k-L));
      ans = max(ans, other + pre);
    }
    else update(L, dis, max(pre, other));
    for(auto ed : adj[nd]){
        if(ed == pr || vis[ed]) continue;
        dfs(ed, nd, pr, dis + 1, cur, L, B, T);
    }
}
bool srt(int a, int b){
    return c[a] < c[b];
}
void cen(int nd, int C = 1){
    gsz(nd, -1); nd = cent(nd, -1, sz[nd]), vis[nd] = other = pre = 1;
    sort(adj[nd].begin(), adj[nd].end(), srt);
    for(auto ed : adj[nd]){
        if(vis[ed]) continue;
        if(c[ed] != C){ other = max(other, pre); pre = 1;}
        dfs(ed, nd, 0, 2, 1, 2, 1, 1);
        dfs(ed, nd, 0, 2, 1, 2, 1, 0);
        C = c[ed];
    }
    other = max(other, pre);
    for(int i = 1; i <= other; i++) bit[i] = 0;
    for(auto ed : adj[nd]){
        if(vis[ed]) continue;
        cen(ed);
    }
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    for(int i = 1; i <= n; i++) cin>>c[i];
    for(int i = 1, a, b; i < n; i++){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    cen(1);
    cout<<ans-1<<endl;
}