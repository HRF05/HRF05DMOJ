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
#include <cstring>
using namespace std;
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
vector<vector<pii>> g;
int r, c, n, a;
bool swp(vector<pii> f, vector<pii> s){
    if(f[a].f == s[a].f) return f[a].s < s[a].s;
    else return f[a].f < s[a].f;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>r>>c;
    for(int i = 0; i < r; i++){
        vector<pii> t;
        for(int y = 0, q; y < c; y++){
            cin>>q;
            t.pb(mp(q, 0));
        }
        g.pb(t);
    }
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a;a--;
        for(int i = 0; i < r; i++){
            g[i][a].s = i;
        }
        sort(g.begin(), g.end(), swp);
    }
    for(int i = 0; i < r; i++){
        for(int y = 0; y < c; y++){
            cout<<g[i][y].f<<" ";
        }
        cout<<endl;
    }
}