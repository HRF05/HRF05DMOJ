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
int C, n;
bool l(deque<int> a, deque<int> b){
    while(!a.empty()){
        if(a.front() == b.front() - 1){
            b.pf(a.front());
            a.pop_front();
        }
        else if(a.back() == b.front() - 1){
            b.pf(a.back());
            a.pop_back();
        }
        else if(a.front() == b.back() + 1){
            b.pb(a.front());
            a.pop_front();
        }
        else if(a.back() == b.back() + 1){
            b.pb(a.back());
            a.pop_back();
        }
        else return false;
    }
    return true;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>C;
    for(int j = 0; j < C; j++){
        cin>>n;
        deque<int> a, b, c, d;
        for(int i = 0, t; i < n; i++){
            cin>>t;
            a.pb(t);
            c.pb(t);
        }
        b.pf(a.front());
        a.pop_front();
        d.pf(c.back());
        c.pop_back();
        if(l(a, b) || l(c, d)){
            cout<<"Case #"<<j + 1<<": yes"<<endl;
        }
        else{
            cout<<"Case #"<<j + 1<<": no"<<endl;
        }
    }
}