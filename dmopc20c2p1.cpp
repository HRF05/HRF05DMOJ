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
int n, ar[1001], a = 0, ma = 0;
char c[1001];
set<pii> s;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>c[i];
        if(c[i] == '^'){
            ar[i] = ar[i-1] + 1;
        }
        else if(c[i] == 'v'){
            ar[i] = ar[i-1] - 1;
        }
        else{
            ar[i] = ar[i-1];
        }
        a = min(a, ar[i]);
        ma = max(ma, ar[i]);
    }
    a = abs(a);
    ma += a;
    for(int i = 1; i <= n; i++){
        ar[i] += a;
    }
    for(int i = ma + 2; i > 0; i--){ // 
        string str;
        bool b = false;
        for(int y = 1; y <= n; y++){
            if(ar[y] == i && c[y] == '^'){
                str += '/';
                b = true;
            }
            else if(ar[y] == i - 1 && c[y] != '^'){
                if(c[y] == 'v') str += char(92); // '\' breaks visual studio code
                else if(c[y] == '>') str += '_';
                b = true;
            }
            else{
                str += '.';
            }
        }
        if(b) cout<<str<<endl;
    }
}