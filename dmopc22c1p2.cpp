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
const int MAX = 1e6 + 5;
int n, m, dista[MAX][2], distb[MAX][2], c[MAX], na[MAX][2], nb[MAX][2];
ll ans = INT_MAX;
vector<int> adj[MAX];
bool visa[MAX], visb[MAX];
void bfs(){
    queue<pii> a, b;
    a.push({1, 0}); b.push({n, 0});
    for(int i = 1; i <= n; i++){
        dista[i][0] = distb[i][0] = INT_MAX;
        dista[i][1] = distb[i][1] = INT_MAX;
    }
    visa[1] = 1; visb[n] = 1;
    while(!a.empty() && !b.empty()){
        pii ua = a.front(); pii ub = b.front(); a.pop(); b.pop();
        if(dista[c[ua.f]][0] > ua.s){
            na[c[ua.f]][1] = na[c[ua.f]][0]; na[c[ua.f]][0] = ua.f; 
            dista[c[ua.f]][1] = dista[c[ua.f]][0];
            dista[c[ua.f]][0] = ua.s;
        }
        else if(dista[c[ua.f]][1] > ua.s){
            dista[c[ua.f]][1] = ua.s;
            na[c[ua.f]][1] = ua.f;
        }
        if(distb[c[ub.f]][0] > ub.s){
            nb[c[ub.f]][1] = nb[c[ub.f]][0]; nb[c[ub.f]][0] = ub.f; 
            distb[c[ub.f]][1] = distb[c[ub.f]][0];
            distb[c[ub.f]][0] = ub.s;
        }
        else if(distb[c[ub.f]][1] > ub.s){
            distb[c[ub.f]][1] = ub.s;
            nb[c[ub.f]][1] = ub.f;
        }
        for(auto ed : adj[ua.f]){
            if(!visa[ed]){
                visa[ed] = 1;
                a.push({ed, ua.s + 1});
            }
        }
        for(auto ed : adj[ub.f]){
            if(!visb[ed]){
                visb[ed] = 1;
                b.push({ed, ub.s + 1});
            }
        }
    }
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>c[i];
    }
    for(int i = 0, a, b; i < m; i++){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    bfs();
    for(int i = 1; i <= n; i++){
        if(dista[i][0] != INT_MAX && distb[i][0] != INT_MAX){
            if(na[i][0] == nb[i][0]){
                ans = min(ans, min((ll)dista[i][0] + (ll)distb[i][1], (ll)dista[i][1] + (ll)distb[i][0]));
            }
            else{
                ans = min(ans, (ll)dista[i][0] + (ll)distb[i][0]);
            }
        }
    }
    if(ans == INT_MAX) cout<<-1<<endl;
    else cout<<ans<<endl;
}