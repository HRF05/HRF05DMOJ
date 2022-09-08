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
const int MAX = 1e5 + 5;
ll n, dest, shops, qu, dist[MAX], in[MAX], out[MAX], cnt = 0, prnt[MAX][16], minn[MAX][16], nearest[MAX], mm[MAX];
pii edg[MAX];
bool sl[MAX];
vector<pll> adj[MAX];

void dfs(int nd, int parent){
    in[nd] = cnt++;
    if(sl[nd]) mm[nd] = dist[nd];
    for(auto ed : adj[nd]){
        if(ed.f != parent){
            dist[ed.f] = dist[nd] + ed.s;
            dfs(ed.f, nd);
            mm[nd] = min(mm[nd], mm[ed.f]);
        }
    }
    if(mm[nd] != LLONG_MAX) nearest[nd] = mm[nd] - (dist[nd] * 2);
    minn[nd][0] = nearest[nd];
    prnt[nd][0] = parent;
    out[nd] = cnt++;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>shops>>qu>>dest; dest--;
    for(int i = 1, a, b, w; i < n; i++){
        cin>>a>>b>>w;a--;b--;
        adj[a].pb(mp(b, w));
        adj[b].pb(mp(a, w));
        edg[i] = mp(a, b);
        mm[i] = LLONG_MAX;nearest[i] = LLONG_MAX;
    }
    for(int i = 0, a; i < shops; i++){
        cin>>a;a--;
        sl[a] = true;
    }
    mm[0] = LLONG_MAX; nearest[0] = LLONG_MAX;
    dfs(dest, dest);
    for(int y = 1; y < 16; y++){
        for(int i = 0; i < n; i++){
            prnt[i][y] = prnt[prnt[i][y-1]][y-1];
            minn[i][y] = min(minn[i][y-1], minn[prnt[i][y-1]][y-1]);
        }
    }
    while(qu--){
        int I, R;
        cin>>I>>R;R--;
        int a = edg[I].f, b = edg[I].s, t = R;
        if(in[a] <= in[b] && out[a] >= out[b]){swap(a, b);}
        if(!(in[a] <= in[R] && out[a] >= out[R])){cout<<"escaped"<<endl; continue;}
        ll ans = nearest[a];
        for(int i = 15; i >= 0; i--){
            if(in[a] <= in[prnt[t][i]] && out[a] >= out[prnt[t][i]]){
                ans = min(ans, minn[t][i]);
                t = prnt[t][i];
            }
        }
        if(ans == LLONG_MAX) cout<<"oo"<<endl;
        else cout<<ans + dist[R]<<endl;
    }
}