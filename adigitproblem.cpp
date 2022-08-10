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
#include <cstring>
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
const ll mod = 1e9 + 7;
ll dp[1005][11][2][2], n;
string k;
ll solve(int cur, int lft, bool nts[11], bool T, bool lz){
    if(cur == k.size()) return lft == n;
    if(dp[cur][lft][T][lz] != -1) return dp[cur][lft][T][lz];
    ll hi = T? k[cur] - '0' : 9;
    ll c = 0;
    for(ll i = 0; i <= hi; i++){
        //cout<<i<<endl;
        if(nts[i] && (!lz || i > 0)){
            nts[i] = false;
            c += solve(cur + 1, lft + 1, nts, i == hi && T, lz && i == 0);
            nts[i] = true;
        }
        else{
            c += solve(cur + 1, lft, nts, i == hi && T, lz && i == 0);
        }
        c %= mod;
    }
    return dp[cur][lft][T][lz] = c;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    bool nts[11] { false };
    cin>>n;
    int a;
    for(int i = 0; i < n; i++){
        cin>>a;
        nts[a] = true;
    }
    cin>>k;
    memset(dp, -1, sizeof(dp));
    int t = (n == 1 && a == 0)? 1 : 0;
    cout<<solve(0, 0, nts, true, true) + t<<endl;
}