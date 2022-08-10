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
#define fs first
#define se second
#define pb push_back
#define mp make_pair
#define INF 2e18
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _;
int r, c, q;
bool R[1000], C[1000];
int main(){
    su(r);su(c);
    for(int i = 0; i < r; i++){
        for(int y = 0; y < c; y++){
            char t;
            sc(t);
            if(t == 'X'){
                R[i] = true;
                C[y] = true;
            }
        }
    }
    cin>>q;
    for(int i = 0; i < q; i++){
        int a, b;
        su(a);su(b);
        if(C[a-1] || R[b-1]) cout<<'Y'<<endl;
        else cout<<'N'<<endl;
    }
    cin.sync_with_stdio(0); cin.tie(0);
}