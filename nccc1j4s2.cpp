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
struct tri {int first, second, t;bool operator<(const tri& T){return first < T.first;}};
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
int n;
char g[37][37];
bool ltn = false, rt;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int y = 0; y < n; y++) cin>>g[i][y];
    }
    for(int i = 0; i < n; i++){
        int c[120]{0};
        for(int y = 0; y < n; y++){
            c[g[i][y]]++;
            if(c[g[i][y]] > 1) ltn = true; 
        }
    }
    for(int i = 0; i < n; i++){
        int c[120]{0};
        for(int y = 0; y < n; y++){
            c[g[y][i]]++;
            if(c[g[y][i]] > 1) ltn = true; 
        }
    }
    if(ltn){
        cout<<"No"<<endl;
        return 0;
    }
    for(int i = 1; i < n; i++){
        if(g[i][0] <= g[i-1][0]){
            rt = true;
        }
        if(g[0][i] <= g[0][i-1]){
            rt = true;
        }
    }
    if(rt){
        cout<<"Latin"<<endl;
    }
    else cout<<"Reduced"<<endl;
}