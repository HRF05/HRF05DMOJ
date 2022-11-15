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
struct tri {int first, second, t, i;bool operator<(const tri& T){return first > T.first;}};
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
int n, q, bit[MAX], ans[MAX], y = 0;
pii a[MAX];
tri qu[MAX];
void update(int x, int val){
    for(int i = x; i <= n; i += i&-i) bit[i] += val;
}
int get(int x){
    int ret = 0;
    for(int i = x+1; i > 0; i -= i&-i) ret += bit[i];
    return ret;
}
bool srt(pii a, pii b){ return a.f > b.f; }
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){ cin>>a[i].f; a[i].s = i+1;}
    sort(a, a + n, srt);
    cin>>q;
    for(int i = 0; i < q; i++){ cin>>qu[i].s>>qu[i].t>>qu[i].f; qu[i].i = i;}
    sort(qu, qu + q);
    for(int i = 0; i < q; i++){
        while(y < n && a[y].f >= qu[i].f){ update(a[y].s, a[y].f); y++;}
        ans[qu[i].i] = get(qu[i].t) - get(qu[i].s-1);
    }
    for(int i = 0; i < q; i++) cout<<ans[i]<<endl;
}