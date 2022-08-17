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
using namespace std;
typedef long long ll;
typedef long long unsigned llu;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
struct tri {int first, second, t ;};
#define f first
#define s second
#define pb push_back
#define pf push_front
#define mp make_pair
#define INF 2e18
const int MAX = 1e6 + 5, MX = 2e5 + 5;
int ans, k, c[MAX], sb[MX], t = -1, a[MAX];
bool vis[MX];
vector<pii> adj[MX]; 
void dfs(int s, int p){
    sb[s] = 1;
    for(auto u : adj[s]){
        if(u.f != p && !vis[u.f]) dfs(u.f, s), sb[s] += sb[u.f];
    }
}
void dfsb(int s, int p, int lngth, int w, bool T){
    if(w > k) return;
    for(auto u : adj[s]){
        if(u.f != p && !vis[u.f]) dfsb(u.f, s, lngth+1, w+u.s, T);
    }
    if(!T){
        if(k - w && a[k-w] < t) c[k-w] = c[k+1], a[k-w] = t;
        ans = min(ans, lngth + c[k-w]);
    }
    else{
        if(a[w] < t) c[w] = c[k+1];
        a[w] = t; c[w] = min(c[w], lngth);
    }
}
int cent(int s, int p, int sz){
    for(auto u : adj[s]){
        if(u.f != p && sb[u.f] > sz/2 && !vis[u.f]) return cent(u.f, s, sz);
    }
    return s;
}
void solve(int s){
    dfs(s, -1);
    int centroid = cent(s, -1, sb[s]);
    vis[centroid] = true;
    t++;
    for(auto u : adj[centroid]){
        if(!vis[u.f]){
            dfsb(u.f, centroid, 1, u.s, false);
            dfsb(u.f, centroid, 1, u.s, true);
        }
    }
    for(auto u : adj[centroid]){
        if(!vis[u.f]) solve(u.f);
    }
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int N, K;
    cin>>N>>K;
    ans = N+1; k = K; c[0] = 0;
    for(int i = 1; i <= k + 1; i++) c[i] = N + 1;
    for(int i = 0, a, b, c; i < N - 1; i++){
        cin>>a>>b>>c;
        a++;b++;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
        
    }
    solve(1);
    cout<<((ans != N+1)? ans : -1)<<endl;
}