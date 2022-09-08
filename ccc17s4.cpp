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
struct tri {ll first, second, t; bool b;bool operator<(const tri& T){return (t == T.t)? b < T.b : t < T.t;}};
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
vector<tri> edg;
ll n, m, d, ds[MAX], ans = 0, e = 0, heavy = 0;
ll get(ll a){
    return ds[a] = (a == ds[a])? a : get(ds[a]);
}
bool merge(ll a, ll b){
    ll x = get(a), y = get(b);
    if(y != x){
        ds[x] = y;
        return true;
    }
    return false;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>d;
    for(ll i = 0; i < m; i++){
        tri t;
        cin>>t.f>>t.s>>t.t;
        if(i < n-1) t.b = false;
        else t.b = true;
        edg.pb(t);
    }
    sort(edg.begin(), edg.end());
    for(ll i = 1; i <= n; i++) ds[i] = i;
    for(auto ed : edg){
        if(e == n-1) break;
        if(merge(ed.f, ed.s)){
            heavy = max(heavy, ed.t);
            e++;
            if(ed.b) ans++;
        }
    }
    for(ll i = 1; i <= n; i++) ds[i] = i;
    for(auto ed : edg){
        if(get(ed.f) != get(ed.s)){
            if(ed.t < heavy || (ed.t == heavy && !ed.b)) merge(ed.f, ed.s);
            else if(!ed.b && ed.t <= d){
                cout<<ans-1<<endl;
                return 0;
            }
        }
    }
    cout<<ans<<endl;
}