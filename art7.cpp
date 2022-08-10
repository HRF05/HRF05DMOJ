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
ll dp[100005][3][2];
const ll mod = 1e9 + 7;
string k;
ll solve(int cur, int st, bool T){
    if(cur == k.size()) return st == 2;
    if(dp[cur][st][T] != -1) return dp[cur][st][T];
    int mi = st == 2? 1 : 0, hi = T? k[cur] - '0' : 9;
    ll c = 0;
    for(int i = mi; i <= hi; i++){
        int sT = st;
        if(st == 0 && i == 1) sT = 1;
        else if(st == 1 && i == 0) sT = 2;
        c += solve(cur + 1, sT, i == hi && T);
        c %= mod;
    }
    return dp[cur][st][T] = c;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>k;
    if(k.length() == 1){
        cout<<0<<endl;
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    cout<<solve(0, 0, true)<<endl;
}