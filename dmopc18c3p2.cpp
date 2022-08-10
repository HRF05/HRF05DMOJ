#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
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
#define mp make_pair
#define INF 2e18
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
const int MAX = 100001;
char _; bool _sign;
tri dp[MAX];
int n, a[MAX], b[MAX];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    su(n);
    for(int i = 1; i <= n; i++){
        si(a[i]);
    }
    dp[0].f = 0; dp[0].s = 0; dp[0].t = 0;
    for(int i = 1; i <= n; i++){
        si(b[i]);
        dp[i].f = max(max(dp[i-1].s, dp[i-1].f), dp[i-1].t) + b[i];
        dp[i].s = dp[i-1].f + a[i];
        dp[i].t = dp[i-1].s + a[i];
    }
    cout<<max(max(dp[n].f, dp[n].s), dp[n].t)<<endl;
}