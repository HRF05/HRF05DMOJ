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
struct tri {int first, second, t;bool operator<(const tri& T){return t < T.t;}};
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
const int MAX = 5e4 + 5;
int pr[MAX][6], h[MAX], n, m, ds[MAX], ans = INT_MAX, cost = 0;
pii cs[MAX][6]; 
vector<tri> edg, uns;
vector<pii> adj[MAX];
inline int find(int a){
    return ds[a] = a == ds[a]? a : find(ds[a]);
}
bool merge(int a, int b){
    int x = find(a), y = find(b);
    if(x != y) return ds[x] = y;
    return 0;
}
int gmax(int cur, int other, int val){
    if(other < val) return max(cur, other);
    else return cur;
}
void dfs(int nd, int prt, int height, int weight){
    pr[nd][0] = prt;
    cs[nd][0].f = weight;
    cs[nd][0].s = -1;
    h[nd] = height;
    for(int i = 1; i < 6; i++){
        pr[nd][i] = pr[pr[nd][i-1]][i-1];
        cs[nd][i].f = max(cs[nd][i-1].f, cs[pr[nd][i-1]][i-1].f);
        cs[nd][i].s = gmax(gmax(max(cs[nd][i].s, max(cs[nd][i-1].s, cs[pr[nd][i-1]][i-1].s)), cs[nd][i-1].f, cs[nd][i].f), cs[pr[nd][i-1]][i-1].f, cs[nd][i].f);
    }
    for(auto ed : adj[nd]){
        if(ed.f == prt) continue;
        dfs(ed.f, nd, height + 1, ed.s);
    }
}
int query(int a, int b, int V){
    if(h[a] < h[b]) swap(a, b);
    int t = h[a]-h[b], ret = -1;
    for(int i = 0; i < 6; i++){
        if((t>>i)&1){
            ret = gmax(gmax(ret, cs[a][i].f, V), cs[a][i].s, V);
            a = pr[a][i];
        }
    }
    if(a == b) return ret;
    for(int i = 5; i >= 0; i--){
        if(pr[a][i] != pr[b][i]){
            ret = gmax(gmax(gmax(gmax(ret, cs[a][i].f, V), cs[a][i].s, V), cs[b][i].f, V), cs[b][i].s, V);
            a = pr[a][i]; b = pr[b][i];
        }
    }
    ret = gmax(gmax(gmax(gmax(ret, cs[a][0].f, V), cs[a][0].s, V), cs[b][0].f, V), cs[b][0].s, V);
    return ret;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i = 0, a, b, c; i < m; i++){
        cin>>a>>b>>c;
        edg.pb({a, b, c});
    }
    sort(edg.begin(), edg.end());
    for(int i = 1; i <= n; i++) ds[i] = i;
    for(auto ed : edg){
        if(merge(ed.f, ed.s)){
            cost += ed.t;
            adj[ed.f].pb({ed.s, ed.t});
            adj[ed.s].pb({ed.f, ed.t});
        }
        else uns.pb(ed);
    }
    if(m-uns.size() != n-1){
        cout<<-1<<endl;
        return 0;
    }
    dfs(1, 0, 0, 0);
    for(auto ed : uns){
        int old = query(ed.f, ed.s, ed.t);
        if(old != -1) ans = min(ans, ed.t - old);
    }
    if(ans == INT_MAX) cout<<-1<<endl;
    else cout<<cost+ans<<endl;
}