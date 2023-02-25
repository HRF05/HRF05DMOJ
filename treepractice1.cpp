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
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
const int MAX = 5e5 + 5;
int n, dis[2][MAX], ans = INT_MAX;
vector<pii> adj[MAX];
void dfs(int nd, int pr, int dist, bool t){
    dis[t][nd] = dist;
    for(auto ed : adj[nd]){
        if(ed.f == pr) continue;
        dfs(ed.f, nd, dist+ed.s, t);
    }
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 1, a, b, c; i < n; i++){
        cin>>a>>b>>c;
        adj[a].pb({b, c}); adj[b].pb({a, c});
    }
    dfs(1, 0, 0, 0);
    int st = 1;
    for(int i = 1; i <= n; i++){
        if(dis[0][i] > dis[0][st]) st = i;
    }
    dfs(st, 0, 0, 0);
    for(int i = 1; i <= n; i++){
        if(dis[0][i] > dis[0][st]) st = i;
    }
    dfs(st, 0, 0, 1);
    cout<<dis[0][st]<<endl;
    for(int i = 1; i <= n; i++){
        ans = min(ans, max(dis[0][i], dis[1][i]));
    }
    cout<<ans<<endl;
}