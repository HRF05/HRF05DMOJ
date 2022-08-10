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
const double error = 1e-7;
bool vis[1001];
int nd = 0, n;
pii ar[1001];
double h = 1e9, l = 0;
inline ll sqrd(pii a, pii b){
    return (ll(a.f - b.f) * ll(a.f - b.f)) + (ll(a.s - b.s) * ll(a.s - b.s));
}
void dfs(int x, double r){
    nd++;
    vis[x] = true;
    for(int i = 0; i < n; i++){
        if(i != x && !vis[i] && (double)sqrt(sqrd(ar[x], ar[i])) < 2 * r){
            dfs(i, r);
        }
    }
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>ar[i].f>>ar[i].s;
    }
    while(h - l > error){
        double m = (h + l) / 2;
        nd = 0;
        for(int i = 0; i < n; i++) vis[i] = false;
        dfs(0, m);
        if(nd == n){
            h = m;
        }
        else{
            l = m;
        }
    }
    cout<<fixed<<setprecision(7)<<l<<endl;
}