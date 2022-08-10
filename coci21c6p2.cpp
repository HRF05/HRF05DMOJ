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
const int MAX = 505;
ll r, s, a, b, g[MAX][MAX], h[MAX], ans = INF;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>r>>s>>a>>b;
    if(a > b) swap(a, b);
    for(int i = 1; i <= r; i++){
        for(int y = 1; y <= s; y++){
            cin>>g[i][y];
            g[i][y] += g[i][y - 1];
        }
    }
    for(int i = 1; i <= s; i++){
        for(int y = i; y <= s; y++){
            int l = 0;
            for(int j = 1; j <= r; j++) h[j] = h[j-1] + g[j][y] - g[j][i-1];
            for(int j = 1; j <= r; j++){
                while(h[j] - h[l] > b) l++;
                ll t = h[j] - h[l];
                ans = min(ans, abs(a - t) + abs(b - t));

            }
        }
    }
    cout<<ans<<endl;
}