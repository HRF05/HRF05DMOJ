#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_set>
#include <list>
#include <string>
#include <stack>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <random>
#include <map>
#include <unordered_map>
#include <complex>
#include <algorithm>
#include <climits>
#include <cstring>
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
const int MX = 2e5 + 5;
int n, k, sz[MX], c, in[MX], tour[MX * 2], diff[MX * 2], tot = 0, ans[MX];
gp_hash_table<int, int> fr, curfr;
vector<pii> adj[MX], path;
bool vis[MX];
void gsz(int s, int p){ // Worst case 1.9s (tle is 2s). without optimization this version of sol wont pass
    sz[s] = 1;
    for(auto u : adj[s]){
        if(u.f != p && !vis[u.f]) gsz(u.f, s), sz[s] += sz[u.f];
    }
}
void dfsb(int s, int p){
    in[s] = ++c;
    tour[c] = s; diff[c] = 0;
    for(auto u : adj[s]){
        if(u.f != p && !vis[u.f]) dfsb(u.f, s);
    }
    c++;
    tour[c] = -s; diff[c] = 0;
}
int cent(int s, int p, int szz){
    for(auto u : adj[s]){
        if(u.f != p && !vis[u.f] && szz / 2 < sz[u.f]) return cent(u.f, s, szz);
    }
    return s;
}
void dfs(int s, int p, int w, bool T){
    if(w > k) return;
    for(auto u : adj[s])
        if(u.f != p && !vis[u.f]) dfs(u.f, s, w + u.s, T);
    if(T) path.pb(mp(s, w));
    curfr[w]++;
}
void solve(int s){
    c = 0;
    gsz(s, -1);
    int nd = cent(s, -1, sz[s]), cint = 0;
    vis[nd] = true; fr.clear(); fr[0] = 1;
    dfsb(nd, -1);
    for(auto u : adj[nd]){
        if(!vis[u.f]){
            curfr.clear();
            dfs(u.f, nd, u.s, false);
            for(auto e : curfr) cint += fr[k - e.f] * e.s;

            for(auto e : curfr) fr[e.f] += e.s;
        }
    }
    for(auto u : adj[nd]){
        if(!vis[u.f]){
            curfr.clear();
            path.clear();
            dfs(u.f, nd, u.s, true);
            for(auto e : path){
                int t = fr[k-e.s] - curfr[k-e.s];
                diff[1] += t;
                diff[in[e.f]+1] -= t;
            }
        }
    }
    for(int i = 1; i <= c; i++){
        diff[i] += diff[i-1];
        if(abs(tour[i]) != nd){
            if(tour[i] < 0) ans[-tour[i]] -= diff[i];
            else ans[tour[i]] += diff[i];
        }
    }
    ans[nd] += cint; tot += cint;
    for(auto u : adj[nd]){
        if(!vis[u.f]) solve(u.f);
    }
}
int main(){
    su(n);su(k);
    for(int i = 1, a, b, c; i < n; i++){
        su(a);su(b);su(c);
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    solve(1);
    for(int i = 1; i <= n; i++){
        int gcd = __gcd(ans[i], tot);
        if(ans[i]) cout<<ans[i] / gcd<<" / "<<tot / gcd<<"\n";
        else cout<<0<<" / "<<1<<"\n";
    }
}