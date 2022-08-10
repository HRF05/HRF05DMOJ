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
int n, a[300001];
ll big = 0, smal = 0;
pii cb[300001], cs[300001];
stack<int> s1, s2, s3, s4;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    su(n);
    for(int i = 0; i < n; i++){
        su(a[i]);

        while(!s2.empty() && a[s2.top()] < a[i]) s2.pop();
        if(s2.empty()) cb[i].f = -1;
        else cb[i].f = s2.top();
        s2.push(i);

        while(!s4.empty() && a[s4.top()] > a[i]) s4.pop();
        if(s4.empty()) cs[i].f = -1;
        else cs[i].f = s4.top();
        s4.push(i);
    }
    for(int i = n - 1; i >= 0; i--){

        while(!s1.empty() && a[s1.top()] <= a[i]) s1.pop();
        if(s1.empty()) cb[i].s = n;
        else cb[i].s = s1.top();
        s1.push(i);

        while(!s3.empty() && a[s3.top()] >= a[i]) s3.pop();
        if(s3.empty()) cs[i].s = n;
        else cs[i].s = s3.top();
        s3.push(i);
    }
    for(int i = 0; i < n; i++){
        big += (ll)a[i] * ll(i - cb[i].f) * ll(cb[i].s - i);
        smal += (ll)a[i] * ll(i - cs[i].f) * ll(cs[i].s - i);
    }
    cout<<big - smal<<endl;
}