#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define first F
#define second S
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define INF 2e18
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
ll q, n, psa[1414215], g = 0;
int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin>>n>>q;
    for(int i = 0; i <= 1414214; i++){
        psa[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin>>a>>b;
        ll t = ceil(sqrt((a * a) + (b * b)));
        if(t > g) g = t;
        psa[t]++;
    }
    for(int i = 1; i <= 1414214; i++){
        psa[i] += psa[i-1];
    }
    for(int i = 0, a; i < q; i++){
        cin>>a;
        cout<<psa[a]<<endl;
    }
}