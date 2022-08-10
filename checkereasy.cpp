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
int n, m, g[3001][3001];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    while(n){
        int a, b, c;
        cin>>a>>b>>c;
        if(!a && !b && !c) break;
        if((a + b) % 2 != 0){
            g[a][b] = -c;
        }
        else{
            g[a][b] = c;
        }
    }
    for(int i = 1; i <= n; i++){
        for(int y = 1; y <= m; y++){
            g[i][y] = g[i][y] + g[i][y-1] + g[i-1][y] - g[i-1][y-1];
        }
    }
    while(n){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        if(!a && !b && !c && !d) break;
        if((a + b) % 2 != 0){
            cout<<-(g[a-1][b-1] + g[c][d] - g[c][b-1] - g[a-1][d])<<endl;
        }
        else{
            cout<<g[a-1][b-1] + g[c][d] - g[c][b-1] - g[a-1][d]<<endl;
        }
    }
}