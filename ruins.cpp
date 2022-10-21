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
const int MAX = 2e3 + 5;
int n, a[MAX], dp[2][MAX], ans = 1e9;
bool c = 1, x = 0;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    su(n);
    for(int i = 1; i <= n; i++) su(a[i]);
    dp[1][1] = 0;
    for(int i = 1; i < n; i++){
        dp[x][i] = 1e9; dp[x][i+1] = 1e9;
        for(int y = 1; y <= i; y++){
            if(a[i+1] <= a[i]) dp[x][y] = dp[c][y] + y;
            else{
                dp[x][y] = min(dp[x][y], dp[c][y] + y * (1 + a[i+1] - a[i]));
                dp[x][y+1] = dp[c][y] + y;
            }
            dp[c][y] = 1e9;
        }
        c = 1 - c; x = 1 - x;
    }
    for(int i = 1; i <= n; i++) ans = min(ans, dp[c][i]);
    cout<<ans<<endl;
}