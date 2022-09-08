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
const int MAX = 1e5 + 5;
ll n, j, dp[MAX], a[MAX], x, y, nh[MAX];
stack<int> s;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>j>>x>>y;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        while(!s.empty() && a[s.top()] <= a[i]){
            nh[s.top()] = i;
            s.pop();
        }
        s.push(i);
        dp[i] = LLONG_MAX;
    }
    dp[0] = 0;
    for(int i = 0; i < n; i++){
        if(i) dp[i] = min(dp[i], dp[i-1] + y);
        if(i - 1 >= 0) dp[i] = min(dp[i], dp[i-2] + y);
        if(nh[i] - i <= j) dp[nh[i]] = min(dp[nh[i]], dp[i] + x);
    }
    cout<<dp[n-1]<<endl;
}