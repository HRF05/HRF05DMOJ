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
const int MAX = 3e6 + 5;
ll n, k, a[MAX], ans = 0;
deque<int> qi, qa;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0, y = 0; i < n; i++){
        while(!qa.empty() && a[qa.back()] < a[i]) qa.pop_back();
        while(!qi.empty() && a[qi.back()] > a[i]) qi.pop_back();
        qi.pb(i); qa.pb(i);
        while(a[qa.front()] - a[qi.front()] > k){
            if(a[qa.front()] == a[y]) qa.pop_front();
            if(a[qi.front()] == a[y]) qi.pop_front();
            y++;
        }
        ans += i - y + 1;
    }
    cout<<ans<<endl;
}