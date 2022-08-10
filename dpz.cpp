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
ll n, c, h[200001], dp[200001];
deque<int> q;
inline double f(int y, int j){
    return double((double)dp[y] - (double)dp[j] + (double)(h[y] * h[y]) - (double)(h[j] * h[j])) / double((double)(2 * h[y]) - (double)(2 * h[j])); 
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>c;
    for(int i = 0; i < n; i++){
        cin>>h[i];
    }
    q.pb(n-1);
    for(int i = n-2; i >= 0; i--){
        while(q.size() > 1 && f(q[0], q[1]) > (double)h[i]) q.pop_front();
        int y = q.front();
        dp[i] = dp[y] + ((h[y] - h[i]) * (h[y] - h[i])) + c;
        while(q.size() > 1 && f(q[q.size() - 2], q[q.size() - 1]) < f(q[q.size() - 1], i)) q.pop_back();
        q.pb(i);
    }
    cout<<dp[0]<<endl;
}