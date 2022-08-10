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
ll n, f, h[1000001], fa[1000001], inf = 200002, ans = 0;
stack<ll> s;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    su(n);su(f);
    cout<<endl;
    for(int i = 0; i < n; i++){
        su(h[i]);
    }
    for(int i = 0; i < f; i++){
        ll a, b;
        su(a);su(b);
        fa[a-1] = max(fa[a-1], b);
    }
    for(int i = 0; i < n; i++){
        if(fa[i]) h[i] -= fa[i];
        else h[i] = inf;
    }
    for(int y = 0; y < n; y++){
        while(!s.empty() && h[y] < h[s.top()]){
            ll H = h[s.top()]; s.pop();
            ll W = s.empty()? -1: s.top();
            if(H != inf) ans = max(ans, (H) * (y - W - 1));
        }
        s.push(y);
    }
    while(!s.empty()){
        ll H = h[s.top()]; s.pop();
        ll W = s.empty()? -1: s.top();
        if(H != inf) ans = max(ans, (H) * (n - W - 1));
    }
    cout<<ans<<endl;
}