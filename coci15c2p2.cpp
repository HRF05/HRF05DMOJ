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
const int MAX = 2e1 + 5;
int n, m;
vector<int> ce[MAX];
int rc(int ls, bool vis[MAX]){
    for(auto ed : ce[ls]){
        if(vis[ed]) return 0;
    }
    vis[ls] = 1;
    int ret = 1;
    for(int i = ls+1; i <= n; i++){
        cout<<i<<" ";
        rc(i, vis);
    }
    vis[ls] = 0;
    return ret;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i = 0, a, b; i < m; i++){
        cin>>a>>b;
        ce[a].pb(b); ce[b].pb(a);
    }
    bool vis[MAX]{0};
    cout<<rc(0, vis)<<endl;
}