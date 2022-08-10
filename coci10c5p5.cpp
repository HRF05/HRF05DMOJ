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
const int MAX = 1e5 + 5;
int n, s, psa[MAX], ans[MAX];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>s;
    for(int i = 1; i <= n; i++){
        cin>>psa[i]; psa[i] += psa[i-1];
    }
    int lf = 1, rt = 0;
    for(int i = 1; i <= n; i++){
        while(lf <= n && psa[i-1] - psa[lf - 1] > s) lf++;
        while(rt + 1 <= n && psa[rt + 1] - psa[i-1] <= s) rt++;
        int w = min(i - lf, rt - i + 1);
        ans[i-w]  = max(ans[i-w], w);
    }
    for(int i = 1; i <= n; i++){
        ans[i] = max(ans[i], ans[i-1] - 1);
        cout<<ans[i] * 2<<endl;
    }
}