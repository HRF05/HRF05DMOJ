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
struct tri {bool first, second, t;};
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
int n, mi = INT_MAX, ind = 0;
vector<int> ar;
tri ans[100001];
stack<int> s1, s2;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 0, a; i < n; i++){
        cin>>a;
        ar.pb(a);
    }
    for(int i = n - 1; i >= 0; i--){
        s1.push(ar[i]);
    }
    sort(ar.begin(), ar.end());
    tri t;
    while(!s1.empty()){
        int mi = ar[0];
        ar.erase(ar.begin());
        int N = 0;
        while(!s1.empty() && s1.top() != mi){
            t.f = false; t.s = false; t.t = false;
            ans[ind] = t;
            ind++;
            t.f = true; t.s = false; t.t = true;
            ans[ind] = t;
            ind++;
            s2.push(s1.top());
            s1.pop();
            N++;
        }
        t.f = false; t.s = true; t.t = false;
        int k = s1.top();
        s1.pop();
        ans[ind] = t;
        ind++;
        for(int i = 0; i < N; i++){
            t.f = false; t.s = false; t.t = true;
            ans[ind] = t;
            ind++;
            t.f = true; t.s = false; t.t = false;
            ans[ind] = t;
            ind++;
            s1.push(s2.top());
            s2.pop();
        }
        t.f = true; t.s = true; t.t = true;
        ans[ind] = t;
        s2.push(k);
        ind++;
    }
    while(!s2.empty()){
        t.f = false; t.s = false; t.t = true;
        ans[ind] = t;
        ind++;
        t.f = true; t.s = false; t.t = false;
        ans[ind] = t;
        ind++;
        s1.push(s2.top());
        s2.pop();
    }
    cout<<ind<<endl;
    for(int i = 0; i < ind; i++){
        if(!ans[i].f) cout<<"UZMI ";
        else cout<<"STAVI ";
        if(!ans[i].s) cout<<"L ";
        else cout<<"D ";
        if(!ans[i].t) cout<<"L";
        else cout<<"D";
        cout<<endl;
    }
}