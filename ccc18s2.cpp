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
int n, g[101][101], st1, en1, st2, en2;
bool up1, up2;
pii mi = mp(0, 0);
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    g[0][0] = INT_MAX;
    for(int i = 1; i <= n; i++){
        for(int y = 1; y <= n; y++){
            cin>>g[i][y];
            if(g[i][y] < g[mi.f][mi.s]) mi = mp(i, y);
        }
    }
    //cout<<mi.f<<" "<<mi.s<<endl;
    if(mi == mp(1, 1)){
        for(int i = 1; i <= n; i++){
            for(int y = 1; y <= n; y++){
                cout<<g[i][y]<<" ";
            } 
            cout<<endl;
        }
    }
    else if(mi == mp(1, n)){
        for(int i = n; i > 0; i--){
            for(int y = 1; y <= n; y++){
                cout<<g[y][i]<<" ";
            } 
            cout<<endl;
        }
    }
    else if(mi == mp(n, 1)){
        for(int i = 1; i <= n; i++){
            for(int y = n; y > 0; y--){
                cout<<g[y][i]<<" ";
            } 
            cout<<endl;
        }
    }
    else if(mi == mp(n, n)){
        for(int i = n; i > 0; i--){
            for(int y = n; y > 0; y--){
                cout<<g[i][y]<<" ";
            } 
            cout<<endl;
        }
    }
}
