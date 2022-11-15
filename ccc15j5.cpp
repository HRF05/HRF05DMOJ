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
int n, k;
int dp[255][255][255];
int get(int pr, int lb, int pi){ // not near tle at all, but probly not intended sol
    if(dp[pi][pr][lb] != -1) return dp[pi][pr][lb];
    if(pr == k) return pi == 0;
    int ret = 0;
    for(int i = lb; i <= pi; i++) ret += get(pr+1, i, pi-i);
    return dp[pi][pr][lb] = ret;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    memset(dp, -1, sizeof(dp));
    cout<<get(0, 1, n)<<endl;
}