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
#define INF (ll)2e18
#define pb push_back
#define pf push_front
#define mp make_pair
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
const int MAX = 101, MX = 1001;
ll n, m, k, b[MAX][MX], s[MAX][MX], g[MAX][MAX], prf[MAX][MAX], gt[MAX][MAX];
void fw(ll graph[MAX][MAX]){
    for(int i = 1; i <= n; i++){
        for(int y = 1; y <= n; y++){
            for(int j = 1; j <= n; j++){
                graph[y][j] = min(graph[y][j], graph[y][i] + graph[i][j]);
            }
        }
    }
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    for(int i = 1; i <= n; i++){
        for(int y = 1; y <= k; y++){
            cin>>b[i][y]>>s[i][y];
        }
        for(int y = 1; y <= n; y++){
            g[i][y] = INF;
        }
    }
    for(int i = 0, a, b, c; i < m; i++){
        cin>>a>>b>>c;
        g[a][b] = c;
    }
    fw(g);
    for(int i = 1; i <= n; i++){
        for(int y = 1; y <= n; y++){
            for(int j = 1; j <= k; j++){
                if(s[y][j] != -1 && b[i][j] != -1) prf[i][y] = max(prf[i][y], s[y][j] - b[i][j]);
            }
        }
    }
    ll l = 1, r = 1e9;
    while(l <= r){
        ll mi = (l + r) / 2;
        for(int i = 1; i <= n; i++){
            for(int y = 1; y <= n; y++){
                gt[i][y] = mi * min(g[i][y], INF / mi) - prf[i][y];
            }
        }
        fw(gt);
        bool B = false;
        for(int i = 1; i <= n; i++){
            if(gt[i][i] <= 0) B = true;
        }
        if(B) l = mi + 1;
        else r = mi - 1;
    }
    cout<<r<<endl;
}

// p/t > r -> p > rt -> p - rt > 0