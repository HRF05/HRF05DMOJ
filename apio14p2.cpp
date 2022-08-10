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
ll dpa[100001], dpb[100001], ar[100001], q[100001];
int n, k, out[201][100001];
inline double r(int j, int k){
    if(ar[j] == ar[k]) return -1;
    return double(dpa[j] - dpa[k] - ar[j] * ar[j] + ar[k] * ar[k]) / double(ar[k] - ar[j]);
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        cin>>ar[i];
        ar[i] += ar[i-1];
    }
    
    for(int i = 1; i <= k; i++){
        int f = 0, b = -1;
        for(int y = 1; y <= n; y++){
            while(f < b && r(q[f], q[f+1]) <= ar[y]) f++;
            int j = q[f];
            dpb[y] = dpa[j] + (ar[y] - ar[j]) * ar[j];
            out[i][y] = j;
            while(f < b && r(q[b - 1], q[b]) >= r(q[b], y)) b--;
            q[++b] = y;
        }
        swap(dpa, dpb);
    }
    cout<<dpa[n]<<endl;
    ll t = out[k--][n];
    while(t){
        cout<<t<<" ";
        t = out[k--][t];
    }
    cout<<endl;
}