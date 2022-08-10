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
char gr[2001][2001];
ll n, m, dp[2001][2001], ans = LLONG_MAX;
deque<int> q;
deque<int> qb;
inline double f(int y, int j, int k){
    return double(dp[j][y] - dp[k][y] + j * j - k * k) / double(2 * (j - k));
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        for(int y = 0; y < n; y++){
            cin>>gr[i][y];
            if(gr[i][y] == '0') dp[i][y] = LLONG_MAX;
            else if(!y && gr[i][y] == '1'){
                dp[i][y] = 0;
                q.pb(i);
            }
        }
    }
    for(int y = 1; y < n; y++){
        for(int i = 0; i < m; i++){
            if(gr[i][y] == '1'){
                while(q.size() > 1 && f(y - 1, q[0], q[1]) < (double)i) q.pop_front();
                int j = q.front();
                dp[i][y] = dp[j][y-1] + (i - j) * (i - j);
                while(qb.size() > 1 && f(y, qb[qb.size() - 2], qb[qb.size() - 1]) > f(y, qb[qb.size() - 1], i)) qb.pop_back();
                qb.pb(i);
            }
        }
        while(!q.empty()) q.pop_front();
        while(!qb.empty()){
            q.pb(qb.front());
            qb.pop_front();
        } 
    }
    for(int i = 0; i < m; i++){
        ans = min(ans, dp[i][n-1]);
    }
    cout<<ans<<endl;
}