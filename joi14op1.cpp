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
const int MAX = 5e5 + 5;
#include "factories.h"
int sz[MAX], cparent[MAX], n, lvl[MAX];
ll dist[MAX][20], distt[MAX];
vector<pii> adj[MAX];
bool vis[MAX];
int gsz(int nd, int prnt){
    sz[nd] = 1;
    for(auto ed : adj[nd]){
        if(ed.f == prnt || vis[ed.f]) continue;
        sz[nd] += gsz(ed.f, nd);
    }
    return sz[nd];
}
int gcent(int nd, int prnt, int ms){
    for(auto ed : adj[nd]){
        if(ed.f != prnt && !vis[ed.f] && sz[ed.f] * 2 > ms) return gcent(ed.f, nd, ms);
    }
    return nd;
}
void dfs(int nd, int prnt, ll distn, int de){
    dist[nd][de] = distn;
    for(auto ed : adj[nd]){
        if(ed.f == prnt || vis[ed.f]) continue;
        dfs(ed.f, nd, distn + ed.s, de);
    }
}
void centdecomp(int nd, int prnt, int de){
    int centroid = gcent(nd, -1, gsz(nd, -1));
    cparent[centroid] = prnt; lvl[centroid] = de;
    vis[centroid] = 1;
    dfs(centroid, -1, 0, de);
    for(auto ed : adj[centroid]){
        if(!vis[ed.f]) centdecomp(ed.f, centroid, de + 1);
    }
}
void Init(int N, int A[], int B[], int D[]){
    n = N;
    for(int i = 0; i < n-1; i++){
        adj[A[i]].pb(mp(B[i], D[i]));
        adj[B[i]].pb(mp(A[i], D[i]));
        distt[i] = INF;
    }
    distt[n-1] = INF;
    centdecomp(0, -1, 0);
}

long long Query(int S, int X[], int T, int Y[]){
	ll ans = INF;
    vector<int> r;
    for(int i = 0; i < S; i++){
        for(int y = X[i]; y != -1; y = cparent[y]){
            distt[y] = min(distt[y], dist[X[i]][lvl[y]]);
            r.pb(y);
        }
    }
    for(int i = 0; i < T; i++){
        for(int y = Y[i]; y != -1; y = cparent[y]){
            ans = min(ans, dist[Y[i]][lvl[y]] + distt[y]);
            r.pb(y);
        }
    }
    for(auto i : r){
        distt[i] = INF;
    }
    return ans;
}