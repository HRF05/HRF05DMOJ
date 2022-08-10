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
typedef vector<pii> vpi;
#define f first
#define s second
#define pb push_back
#define INF 2e18
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
ll i;
int n, k, s[200000];
vpi v;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    scan(n); scan(k);
    for(int i = 0; i < n; i++){
        int T;
        scan(T);
        pii p = {T, i};
        v.pb(p);
        s[i] = 0;
    }
    for(int i = 0; i < k; i++){
        int a, b;
        scan(a); scan(b);
        a--; b--;
        if(v[a].f > v[b].f){
            s[a]--;
        }
        else if(v[b].f > v[a].f){
            s[b]--;
        }
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++){
        int T = i;
        while(v[T].f == v[i].f) T--;
        s[v[i].second] += T + 1;
    }
    for(int i = 0; i < n; i++){
        cout<<s[i]<<" ";
    }
    cout<<endl;
}