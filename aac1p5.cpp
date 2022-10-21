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
const int MAX = 2e5 + 5;
ll ev[MAX]{0}, od[MAX]{0}, n, ans = LLONG_MAX;
vector<pll> adj[MAX];
void dfs(ll nd, ll dist, ll prnt){
    if(dist % 2) od[nd]++;
    else ev[nd]++;
    for(auto ed : adj[nd]){
        if(ed.f == prnt) continue;
        dfs(ed.f, dist+ed.s, nd);
        od[nd] += od[ed.f];
        ev[nd] += ev[ed.f];
    }
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(ll i = 1, a, b, w; i < n; i++){
        cin>>a>>b>>w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }
    dfs(1, 1, 0);
    for(ll i = 1, t; i <= n; i++){
        t = (ev[1] - ev[i] + od[i]) * (od[1] - od[i] + ev[i]);
        ans = min(ans, abs(t * 2 - n * (n-1) / 2));
    }
    cout<<ans<<endl;
}