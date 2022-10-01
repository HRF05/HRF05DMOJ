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
const int MAX = 1e5 + 5, MX = 2e5 + 5;
int n, m, s, e, c, dist[MAX];
bool vis[MAX];
tri in[MX];
int dikstras(int lvl){
    vector<pii> adj[MAX]; queue<int> q;
    for(int i = 0; i < lvl; i++){
        adj[in[i].f].pb({in[i].s, in[i].t});
        adj[in[i].s].pb({in[i].f, in[i].t});
    }
    for(int i = 1; i <= n; i++){dist[i] = INT_MAX; vis[i] = 0;}
    q.push(s);dist[s] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        vis[u] = 0;
        for(auto ed : adj[u]){
            if(dist[u] + ed.s < dist[ed.f]){
                dist[ed.f] = dist[u] + ed.s;
                if(!vis[ed.f]){
                    vis[ed.f] = true;
                    q.push(ed.f);
                }
            }
        }
    }
    return dist[e];
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i = 0, a, b, t; i < m; i++){
        cin>>a>>b>>t;
        in[i] = {a, b, t};
    }
    cin>>s>>e>>c;
    int h = m, l = 1;
    while(l < h){
        int mi = (h + l) / 2;
        if(dikstras(mi) >= c) l = mi + 1;
        else h = mi;
    }
    if(dikstras(h) < c) cout<<h<<endl;
    else cout<<-1<<endl;
}