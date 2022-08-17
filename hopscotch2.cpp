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
#include <cstring>
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
const int MAX = 1e7 + 5;
ll n, j, dp[MAX], a[MAX], pth[MAX];
deque<ll> q;
vector<ll> lexi(vector<ll> I, vector<ll> Y){
    ll szi = I.size(), szy = Y.size();
    if(szi < szy) return Y;
    else if(szi > szy) return I;
    for(ll i = 0; i < szi; i++){
        if(I[szi-i-1] < Y[szi-i-1]) return Y;
        else if(I[szi-i-1] > Y[szi-i-1]) return I;
    }
    return Y;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>j;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        dp[i] = LLONG_MAX;
    }
    dp[0] = 0; q.pf(0);
    for(int i = 1; i <= n; i++){
        if(!q.empty() && q.front() < i - j) q.pop_front();
        int T;
        if(j == 0) T = i-1;
        else T = q.front();
        dp[i] = dp[T] + a[i];
        pth[i] = T;
        while(!q.empty() && dp[q.back()] >= dp[i]) q.pop_back();
        q.pb(i);
    }
    ll mi = LLONG_MAX;
    vector<ll> ans;
    for(int i = n - j + 1; i <= n; i++){
        if(dp[i] < mi){
            mi = dp[i];
            ll ind = i;
            ans.clear();
            while(ind){
                ans.pb(ind);
                ind = pth[ind];
            }
        }
        else if(dp[i] == mi){
            ll ind = i;
            vector<ll> t;
            while(ind){
                t.pb(ind);
                ind = pth[ind];
            }
            ans = lexi(ans, t);
        }
    }
    cout<<mi<<endl;
    for(int i = ans.size() - 1; i >= 0; i--){
        cout<<ans[i]<<" ";
    }
}