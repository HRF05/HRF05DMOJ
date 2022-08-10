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
const int MAX = 2e5 + 5, MX = 6e5 + 5;
int X[MX], Y[MX], s[MAX], b[MAX], n, m, p[MX], q[MX], btwo[MAX], key[MAX];
bool check(int t){
    for(int i = 0; i < n; i++){
        b[i] = s[i];
        btwo[i] = s[i];
        key[s[i]] = i;
    }

    vector<pii> ans;

    for(int i = 0; i < t; i++){
        swap(b[X[i]], b[Y[i]]);
    }

    for(int i = 0; i < n; i++){
        if(b[i] != i){
            ans.pb(mp(b[b[i]], b[i]));
            swap(b[b[i]], b[i]);
            i--;
        }
    }
    if(ans.size() > t) return false;

    for(int i = 0; i < t; i++){
        swap(key[btwo[X[i]]], key[btwo[Y[i]]]);
        swap(btwo[X[i]], btwo[Y[i]]);
        if(i >= ans.size()){
            p[i] = 0;
            q[i] = 0;
            continue;
        }
        swap(btwo[key[ans[i].f]], btwo[key[ans[i].s]]);
        swap(key[ans[i].f], key[ans[i].s]);
        p[i] = key[ans[i].s];
        q[i] = key[ans[i].f];
    }
    return true;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    su(n);
    for(int i = 0; i < n; i++){
        su(s[i]);
    }
    su(m);
    for(int i = 0; i < m; i++){
        su(X[i]);su(Y[i]);
    }
    int hi = m, lo = 0;
    while(lo < hi){
        int mid = (hi + lo) / 2;
        if(check(mid)){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    cout<<lo<<endl;
    for(int i = 0; i < lo; i++){
        cout<<p[i]<<" "<<q[i]<<endl;
    }
    return 0;
}