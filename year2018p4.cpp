#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_set>
#include <list>
#include <string>
#include <stack>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <random>
#include <map>
#include <unordered_map>
#include <cstring>
#include <complex>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;
typedef long long unsigned llu;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
struct tri {int first, second, t ;};
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
ll l, r, digits[20], dp[20][164];
ll d(ll p, ll s, ll y, ll dp[20][164], ll digits[20], bool t){
    if(p < 0) return s == y ? 1 : 0;
    if(dp[p][s] != -1) return dp[p][s];
    ll h = t ? digits[p] : 9;
    ll c = 0;
    for(ll i = 0; i <= h; i++){
        c += d(p - 1, s + i, y, dp, digits, t && i == digits[p]);
    }
    return dp[p][s] = c;
}
ll f(ll x, ll y){
    ll n = 0;
    memset(dp, -1, sizeof(dp));
    for(; x > 0; x /= 10) digits[n++] = x % 10;
    return d(n - 1, 0, y, dp, digits, true);
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>l>>r;
    int ans = 0;
    for(ll i = 0; i < 163; i++){
        if(f(r, i) - f(l - 1, i)) ans++;
    }
    cout<<ans<<endl;
}