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
const double error = 1e-10;
const int MAX = 1e5 + 5;
int n, k, tot[MAX];
double dp[MAX];
inline double f(int i, int y){
    return (dp[i]-dp[y]) / (i-y);
}
int check(double mid){
    deque<int> q;
    q.pb(0);
    for(int i = 1; i <= n; i++){
        while(q.size() > 1 && f(q[0], q[1]) > 1.0/i) q.pop_front();
        int t = q.front();
        dp[i] = dp[t] + double(i - t) / i - mid;
        tot[i] = tot[t] + 1;
        while(q.size() > 1 && f(q[q.size()-2], q[q.size()-1]) < f(q[q.size()-1], i)) q.pop_back();
        q.pb(i);
    }
    return tot[n];
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    double l = 0, r = 1e9, mid;
    while(r - l > error){
        mid = (l + r) / 2;
        if(check(mid) >= k) l = mid;
        else r = mid;
    }
    cout<<fixed<<setprecision(9)<<dp[n] + mid * k<<endl;
}