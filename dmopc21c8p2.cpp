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
const int MAX = 1e6+5, mod = 1e9 + 7;
int n, g[MAX][2], t;
int modpow(ll a, int b){
    if(!a) return 0;
    int ret = 1;
    while(b){
        if(b % 2) ret = (ret * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ret;
}
void end(){ cout<<0<<endl; exit(0); }
int get(bool j){
    int em = 0, ret = 0, m = 2, x = 2 * t;
    for(int i = j; i < n; i+=2){
        if(g[i][0] && g[i][1]){ x = min(x, g[i][0]+g[i][1]); m = max(m, g[i][0]+g[i][1]); }
        else if(g[i][0]){ x = min(x, g[i][0]+t); m = max(m, g[i][0]+1); }
        else if(g[i][1]){ x = min(x, g[i][1]+t); m = max(m, g[i][1]+1); }
        else em++;
    }
    for(int i = m; i <= x; i++) ret = (ret + modpow(i-1-2*(max(0, i-t-1)), em)) % mod;
    return ret;
}
int main() {
    su(n);su(t);
    for(int i = 0; i < n; i++) su(g[i][0]);
    for(int i = 0; i < n; i++) su(g[i][1]);
    cout<<((ll)get(0) * (ll)get(1)) % mod<<endl;
}