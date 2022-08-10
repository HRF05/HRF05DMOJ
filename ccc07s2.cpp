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
int n, m;
const int MAX = 1e4 + 5;
tri t[MAX];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 0, a[3]; i < n; i++){
        cin>>a[0]>>a[1]>>a[2];
        sort(a, a + 3);
        t[i].f = a[0]; t[i].s = a[1]; t[i].t = a[2];
    }
    cin>>m;
    for(int i = 0, a[3]; i < m; i++){
        cin>>a[0]>>a[1]>>a[2];
        sort(a, a + 3);
        int mi = INT_MAX;
        for(int y = 0; y < n; y++){
            if(t[y].f >= a[0] && t[y].s >= a[1] && t[y].t >= a[2]){
                mi = min(mi, t[y].f * t[y].s * t[y].t);
            }
        }
        if(mi != INT_MAX) cout<<mi<<endl;
        else cout<<"Item does not fit."<<endl;
    }
}