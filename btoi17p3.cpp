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
const int MAX = 1e5;
int n, m, k, in[MAX], out[MAX], cnt = 0, prnt[MAX][16], bit[MAX], edg[MAX];
vector<pii> adj[MAX];
void dfs(int nd, int parent){
    in[nd] = ++cnt;
    prnt[nd][0] = parent;
    for(int y = 1; y < 16; y++){
        prnt[nd][y] = prnt[prnt[nd][y-1]][y-1];
    }
    for(auto ed : adj[nd]){
        if(ed.f == parent) continue;
        edg[ed.f] = ed.s;
        dfs(ed.f, nd);
    }
    out[nd] = cnt;
}
bool ancestor(int a, int b){
    return in[a] <= in[b] && out[a] >= out[b];
}
int lca(int a, int b){
    if(ancestor(a, b)) return a;
    if(ancestor(b, a)) return b;
    for(int i = 15; i >= 0; i--){
        if(!ancestor(prnt[a][i], b)) a = prnt[a][i];
    }
    return prnt[a][0];
}
void update(int nd, int vl){
    for(; nd <= n; nd += nd & -nd) bit[nd] += vl;
}
int get(int a, int b){
    int tota = 0, totb = 0;a--;
    for(; b > 0; b -= b & -b) totb += bit[b];
    for(; a > 0; a -= a & -a) tota += bit[a];
    return totb - tota;
}
bool srt(int a, int b){
    return in[a] < in[b];
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    for(int i = 1, a, b; i < n; i++){
        cin>>a>>b; a--;b--;
        adj[a].pb(mp(b, i));
        adj[b].pb(mp(a, i));
    }
    dfs(0, 0);
    
    while(m--){
        int s, choice[MAX];
        cin>>s;
        for(int i = 0; i < s; i++){cin>>choice[i];choice[i]--;}
        sort(choice, choice + s, srt);
        choice[s] = choice[0];
        for(int i = 0; i < s; i++){
            update(in[choice[i]], 1);
            update(in[choice[i+1]], 1);
            update(in[lca(choice[i], choice[i+1])], -2);
        }
    }
    vector<int> ans;
    for(int i = 1; i < n; i++){
        if(get(in[i], out[i]) >= k * 2) ans.pb(edg[i]);
    }
    cout<<endl;
    cout<<ans.size()<<endl;
    sort(ans.begin(), ans.end());
    for(auto r : ans) cout<<r<<" ";
}