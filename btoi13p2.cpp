#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_set>
#include <list>
#include <cstring>
#include <string>
#include <stack>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <random>
#include <map>
#include <unordered_map>
#include <complex> 
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
/*
123 321 should return same as
122 321
*/
ll dp[20][20][2];
string a, b;
bool B = false;
ll solve(ll cur, ll dg, bool T, string k, ll pr2, ll pr1){
    if(cur == k.size()){
        if(T && k == a) B = true;
        return dg > 0;
    }
    if(dp[cur][dg][T] != -1) return dp[cur][dg][T];
    ll h = T? k[cur]-'0' : 9;
    ll c = 0;
    for(ll i = 0; i <= h; i++){
        if(pr2 != i && pr1 != i) c += solve(cur + 1, dg + (i || dg), i == h && T, k, dg? pr1 : -1, (dg || i)? i : -1);
    }
    return dp[cur][dg][T] = c;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>a>>b;
    memset(dp, -1, sizeof(dp));
    ll ta = solve(0, 0, 1, a, -1, -1);
    memset(dp, -1, sizeof(dp));
    ll tb = solve(0, 0, 1, b, -1, -1);
    cout<<tb-ta+B<<endl;
}