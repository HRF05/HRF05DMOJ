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
const int MAX = 2e6 + 5;
ll n, l, dp[MAX], ar[MAX];
deque<int> q;
inline double cht(int y, int j){
    return double(dp[y] - dp[j] + (y + j) * (y - j) + (ar[y] + ar[j]) * (ar[y] - ar[j]) + 2 * (y * (ar[y] + 1) - j * (ar[j] + 1) + ar[y] - ar[j])) / double(2 * (j + ar[j] - y - ar[y]));
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>l;
    for(int i = 1; i <= n; i++){
        cin>>ar[i];
        ar[i] += ar[i-1];
        dp[i] = LLONG_MAX;
    }
    q.pf(0);
    for(ll i = 1; i <= n; i++){
        while(q.size() > 1 && cht(q[0], q[1]) > l - i - ar[i]) q.pop_front();
        int y = q.front();
        ll t = i - y - 1 + ar[i] - ar[y] - l;
        dp[i] = min(dp[i], dp[y] + t * t);
        while(q.size() > 1 && cht(q[q.size() - 2], q[q.size() - 1]) <= cht(q[q.size() - 1], i)) q.pop_back();
        q.pb(i);
    }
    cout<<dp[n]<<endl;
}