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
const int MAX = 1e5 + 5, MX = 1e7;
int n, m;
int dist[MAX][12], disto[MAX][12];
vector<pii> adj[MAX];
void dijkstra(int nd){
    queue<int> q;queue<int> q2;
    for(int i = 1; i <= n; i++){
        for(int y = 0; y < 12; y++) dist[i][y] = MX;
    }
    q.push(nd); dist[nd][0] = 0;
    q2.push(0);
    while(!q.empty()){
        int p = q.front(); q.pop();
        int j = q2.front(); q2.pop();
        for(auto ed : adj[p]){
            if(dist[ed.f][(dist[p][j] + ed.s) % 12] > dist[p][j] + ed.s){
                dist[ed.f][(dist[p][j] + ed.s) % 12] = dist[p][j] + ed.s;
                q.push(ed.f);
                q2.push((dist[p][j] + ed.s) % 12);
            }
        }
    }
}
void dijkstras(){
    dijkstra(1);
    for(int i = 1; i <= n; i++){
        for(int y = 0; y < 12; y++) disto[i][y] = dist[i][y];
    }
    dijkstra(n);
    for(int i = 1; i <= n; i++){
        int mi = MX;
        for(int j = 0; j < 12; j++){
            if(disto[i][j] != MX && dist[i][j] != MX) mi = min(mi, max(dist[i][j], disto[i][j]));
        }
        if(mi == MX) cout<<-1<<"\n";
        else cout<<mi<<"\n";
    }
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    su(n);su(m);
    for(int i = 0, a, b, c; i < m; i++){
        su(a);su(b);su(c);
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    dijkstras();
}