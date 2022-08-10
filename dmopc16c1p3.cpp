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
double dp[10001];
int n, t = 0, pre1, pre2;
double dp1(int a, int b){
    double ns, nb;
    if(a > b){
        nb = a; ns = b;
    }
    else{
        nb = b; ns = a;
    }
    return nb + ns / 2;
}
double dp2(int a, int b, int c){
    int ns, nb, nB;
    if(a > b){
        nb = a; ns = b;
    }
    else{
        nb = b; ns = a;
    }
    if(ns > c)
        nB = ns;
    else
        nB = c;
    return nb + nB;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){
        int a;
        double i2 = (i - 2 < 0)? 0 : dp[i - 2], i3 = (i - 3 == -1)? 0 : dp[i - 3];
        cin>>a;
        if(i-1 < 0){
            pre1 = a;
            dp[i] = a;
            continue;
        }
        
        dp[i] = min(dp[i-1]+double(a), i2 + dp1(a, pre1));
        if(i - 3 > -2) dp[i] = min(dp[i], i3 + dp2(a, pre1, pre2));
        pre2 = pre1;
        pre1 = a;
    }
    cout<<fixed<<setprecision(1)<<dp[n-1]<<endl;
}