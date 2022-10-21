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
struct tri {ll first, second, t;bool operator<(const tri& T){return first < T.first;}};
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
const int mod = 1e9 + 7, b = 31, MAX = 55;
ll n, k, ans[MAX]; gp_hash_table<ll, ll> m[MAX]; string s;
tri get(int n){
    ll ret = 0, reta = 0, retb = 0;
    for(int i = 0; i < n; i++) ret = ret*b + s[i];
    for(int i = 0; i < n-1; i++) reta = reta*b + s[i];
    for(int i = 1; i < n; i++) retb = retb*b + s[i];
    tri t = {reta, retb, ret};
    return t;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    for(int i = 1; i <= k; i++){
        cin>>s;
        m[1][s[0]]++;
    }
    for(int i = 2; i <= n; i++){
        for(int y = 1; y <= k; y++){
            cin>>s;
            tri hsh = get(i);
            ll r;
            if(hsh.f == hsh.s) r = m[i-1][hsh.f];
            else r = (m[i-1][hsh.f] + m[i-1][hsh.s]) % mod;
            ans[i] = (ans[i] + r) % mod;
            m[i][hsh.t] = (m[i][hsh.t] + r) % mod;
        }
    }
    cout<<ans[n]<<endl;
}