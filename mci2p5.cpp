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
int n, m, k, tot[MAX]; ll c[MAX], giv[MAX], ans = 0;
vi adj[MAX];
queue<int> q;
ll dfs(int nd){
    ll ret = 1; if(giv[nd]) return giv[nd]/c[nd];
    for(auto ed : adj[nd]){
        ret += dfs(ed);
    }
    giv[nd] = c[nd] * ret;
    return ret;
}
signed main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    for(int i = 1; i <= n; i++) cin>>c[i];
    while(m--){
        int a, b; cin>>a>>b;
        adj[a].pb(b); tot[b]++;
    }
    for(int i = 1; i <= n; i++){
        if(!tot[i]){
            dfs(i);
            q.push(i);
        }
    }
    sort(giv+1, giv+n+1, greater<ll>());
    for(int i = 1; i <= k; i++) ans -= giv[i];
    while(!q.empty()){
        int u = q.front(); q.pop();
        ans += c[u];
        for(auto ed : adj[u]){
            tot[ed]--;
            c[ed] += c[u];
            if(!tot[ed]) q.push(ed);
        }
    }
    cout<<ans<<endl;
}