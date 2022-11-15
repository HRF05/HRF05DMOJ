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
const int MAX = 2e5 + 5;
int n;
vector<int> rt, adj[MAX];
vector<pii> gr[MAX];
void dfs(int nd, int pr, int pr2, int anc, bool pa){
    if(!pr2) rt.pb(anc = nd);
    else if(pa) gr[anc].pb({nd, pr2});
    else gr[1].pb({nd, pr2});
    for(auto ed : adj[nd]){
        if(ed == pr) continue;
        dfs(ed, nd, pr, anc, 1-pa);
    }
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 1, a, b; i < n; i++){
        cin>>a>>b;
        adj[b].pb(a); adj[a].pb(b);
    }
    dfs(1, 0, 0, 0, 0);
    cout<<rt.size()<<endl;
    for(auto re : rt){
        cout<<gr[re].size()+1<<endl;
        for(auto ed : gr[re]){
            cout<<ed.s<<" "<<ed.f<<endl;
        }
    }
}