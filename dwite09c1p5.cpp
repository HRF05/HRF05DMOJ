#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
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
const int MAX = 1e2 + 5;
bool vis[MAX];
int n;
vi adj[MAX];
int dfs(int nd, int i){
    if(nd == i && vis[nd]) return 1;
    for(auto ed : adj[nd]){
        if(vis[ed]) continue;
        vis[ed] = 1;
        int c = dfs(ed, i);
        if(c) return c+1;
    }
    return 0;
}
void solve(){
    cin>>n;
    for(int i = 1; i <= n; i++) adj[i].clear();
    for(int i = 0, a, b; i < n; i++){
        cin>>a>>b;
        adj[a].pb(b);
    }
    
    for(int i = 1, c; i <= n; i++){
        c = dfs(i, i);
        for(int i = 1; i <= n; i++) vis[i] = 0;
        if(c){ cout<<c-1<<endl; break;}
    }
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    for(int i = 0; i < 5; i++){
        solve();
    }
}