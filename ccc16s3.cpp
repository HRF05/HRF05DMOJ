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
struct tri {int first, second, t;bool operator<(const tri& T){return second > T.second;}};
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
int n, m, st, tot = 0, mx, id;
vi adj[MAX];
bool vis[MAX], ph[MAX];
void dfs(int nd, int pr){
    vis[nd] = 1-ph[nd];
    for(auto ed : adj[nd]){
        if(ed == pr) continue;
        dfs(ed, nd);
        vis[nd] = min(vis[nd], vis[ed]);
    }
    tot += 1-vis[nd];
}
void mxd(int nd, int pr, int dis){
    for(auto ed : adj[nd]){
        if(vis[ed] || ed == pr) continue;
        mxd(ed, nd, dis+1);
    }
    if(dis > mx) mx = dis, id = nd;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i = 0, a; i < m; i++){
        cin>>a; ph[a] = 1; st = a;
    }
    for(int i = 1, a, b; i < n; i++){
        cin>>a>>b;
        adj[a].pb(b); adj[b].pb(a);
    }
    dfs(st, -1); mxd(st, -1, 0); mxd(id, -1, 0);
    cout<<(tot-1)*2-mx<<endl;
}