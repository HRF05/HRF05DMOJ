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
const int MAX = 2e4 + 5;
ll n, m, dist[MAX][2];
priority_queue<pii, vector<pii>, greater<pii>> q;
vector<pii> adj[MAX];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i = 0, a, b, w; i < m; i++){
        cin>>a>>b>>w;
        adj[a].pb({b, w});
    }
    for(int i = 0; i <= n; i++){
        dist[i][0] = dist[i][1] = INT_MAX;
    }
    dist[1][0] = 0;
    q.push({0, 1});
    while(!q.empty()){
        int u = q.top().s; q.pop(); 
        for(pii ed : adj[u]){
            if(ed.s + dist[u][0] < dist[ed.f][0]){
                dist[ed.f][1] = dist[ed.f][0];
                dist[ed.f][0] = ed.s + dist[u][0];
                q.push({dist[ed.f][0], ed.f});
            }
            else if(ed.s + dist[u][0] < dist[ed.f][1] && dist[ed.f][0] != ed.s + dist[u][0]){
                dist[ed.f][1] = ed.s + dist[u][0];
                q.push({dist[ed.f][1], ed.f});
            }
            else if(ed.s + dist[u][1] < dist[ed.f][1]){
                dist[ed.f][1] = ed.s + dist[u][1];
                q.push({dist[ed.f][1], ed.f});
            }
        }
    }
    if(dist[n][1] == INT_MAX) cout<<-1<<endl;
    else cout<<dist[n][1]<<endl;
}