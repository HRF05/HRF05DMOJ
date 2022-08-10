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
ll dp[100005][105][2], d;
string k;
int solve(int ls, int num, bool T){
    if(ls == k.size()){
        return num == 0;
    }
    if(dp[ls][num][T] != -1) return dp[ls][num][T];
    ll c = 0;
    int h = T? k[ls] - '0' : 9;
    for(int i = 0; i <= h; i++){
        c += solve(ls + 1, (num + i) % d, i == h && T);
        c %= mod;
    }
    return dp[ls][num][T] = c;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin>>k>>d;
    cout<<(solve(0, 0, true) - 1 + mod) % mod<<endl;
}