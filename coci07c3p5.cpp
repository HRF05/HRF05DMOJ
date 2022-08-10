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
#include <cstring>
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
ll s, dp[20][140][2];
string a, b;
ll solve(int cur, int sm, bool T, string k){
    if(cur == k.size()) return sm == s;
    if(dp[cur][sm][T] != -1) return dp[cur][sm][T];
    int mx = T? k[cur] - '0' : 9;
    ll c = 0;
    for(int i = 0; i <= mx; i++){
        c += solve(cur + 1, sm + i, i == mx && T, k);
    }
    return dp[cur][sm][T] = c;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>a>>b>>s;
    memset(dp, -1, sizeof(dp));
    ll t = solve(0, 0, 1, b);
    memset(dp, -1, sizeof(dp));
    ll ta = solve(0, 0, 1, a);
    cout<<t - ta<<endl;
    ll h = stoll(b), l = stoll(a);
    while(h >= l){
        ll mid = (h + l) / 2;
        memset(dp, -1, sizeof(dp));
        string mi = to_string(mid);
        ll tm = solve(0, 0, 1, mi);
        if(tm - ta < 1){
            l = mid + 1;
        }
        else{
            h = mid - 1;
        }
    }
    cout<<l<<endl;
}