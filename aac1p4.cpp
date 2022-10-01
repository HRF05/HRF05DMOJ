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
struct tri {int first, second, t, i;bool operator<(const tri& T){return second < T.second;}};
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
const int MAX = 1e6 + 5, MX = 5e4 + 5, mX = 1e5 + 5;
int n, q, a[MAX], m[mX];
bool ans[MX];
tri qu[MX];
int main() {
    su(n);su(q);
    for(int i = 1; i <= n; i++) su(a[i]);
    for(int i = 0; i < q; i++){
        su(qu[i].f);su(qu[i].s);su(qu[i].t);qu[i].i = i;
    }
    sort(qu, qu + q);
    for(int i = 0; i < q; i++){
        for(int y = qu[i-1].s+1; y <= qu[i].s; y++) m[a[y]] = y;
        for(int y = 1; y < sqrt(qu[i].t); y++){
            if(!(qu[i].t % y) && m[y] >= qu[i].f && m[qu[i].t / y] >= qu[i].f){
                ans[qu[i].i] = 1;
                break;
            }
        }
    }
    for(int i = 0; i < q; i++){
        if(ans[i]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}