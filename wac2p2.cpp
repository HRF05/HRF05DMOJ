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
const int MAX = 2e5 + 5;
ll n, m, q, ans = 0;
pll ar[MAX];
vector<tri> gt; unordered_set<ll> s;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>q;
    for(int i = 0; i < q; i++) cin>>ar[i].f>>ar[i].s;
    for(int i = 0; i < q-1; i++) gt.pb({ar[i].s, ar[i].f, ar[i+1].f});
    gt.pb({ar[q-1].s, ar[q-1].f, 1}); sort(gt.begin(), gt.end());
    for(int i = 0; i < gt.size() && m > 0; i++){
        bool T = 1-s.count(gt[i].t), T1 = 1-s.count(gt[i].s);
        ans += gt[i].f*min(max(gt[i].s-gt[i].t+T+T1-1, 0ll), m); 
        m -= min(max(gt[i].s-gt[i].t+T+T1-1, 0ll), m);
        s.insert(gt[i].s); s.insert(gt[i].t);
    }
    cout<<ans+1000000*m<<"\n";
}