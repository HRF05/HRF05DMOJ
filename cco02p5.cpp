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
struct tri {int first, second; double t;bool operator<(const tri& T){return t < T.t;}};
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
const int MAX = 1e4 + 5;
int n, ds[MAX], m, e = 0;
double ans = 0;
pii loc[MAX];
vector<tri> edg;
vector<pii> out;
inline double dist(int x, int y, int x1, int y1){
    double a = abs(x - x1), b = abs(y - y1);
    return sqrt(a * a + b * b);
}
int find(int a){
    return ds[a] = (ds[a] == a)? a : find(ds[a]);
}
bool merge(int a, int b){
    int x = find(a), y = find(b);
    if(x == y) return 0;
    ds[x] = y;
    return 1;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>loc[i].f>>loc[i].s;
    }
    cin>>m;
    for(int i = 1; i <= n; i++) ds[i] = i;
    for(int i = 0, a, b; i < m; i++){
        cin>>a>>b;
        merge(a, b);
    }
    for(int i = 1; i <= n; i++){
        for(int y = 1; y <= n; y++){
            if(i != y) edg.pb({i, y, dist(loc[i].f, loc[i].s, loc[y].f, loc[y].s)});
        }
    }
    sort(edg.begin(), edg.end());
    for(auto ed : edg){
        if(e == n-1) break;
        if(merge(ed.f, ed.s)){
            e++;
            ans += ed.t;
            out.pb({ed.f, ed.s});
        }
    }
    cout<<fixed<<setprecision(2)<<ans<<endl;
    for(auto t : out){
        cout<<t.f<<" "<<t.s<<endl;
    }
}