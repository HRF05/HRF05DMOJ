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
const ll MOD = 1e9 + 7;
ll n, ans = 0, po;
ll modmul(ll a, ll b){
    ll res = 0;
    a %= MOD;
    while(b){
        if(b & 1) res = (res + a) % MOD;
        a += a;
        a %= MOD;
        b /= 2;
    }
    return res % MOD;
}
ll modpow(ll a, ll b){
    ll res = 1;
    a %= MOD;
    while(b){
        if(b & 1) res = modmul(res, a);
        a = modmul(a, a);
        b /= 2;
    }
    return res % MOD;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    po = modpow(2, (n - 1));
    for(int i = 1, a; i <= n; i++){
        cin>>a;
        ans += modmul(po, a);
    }
    cout<<ans % MOD<<endl;
}