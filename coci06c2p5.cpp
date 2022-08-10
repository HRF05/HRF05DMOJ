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
#define forn(i,e) for(ll i = 0; i < e; i++)
#define pb push_back
#define mp make_pair
#define INF 2e18
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int i, y, w, h, psax[400][400], psay[400][400], ans = 0;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>w>>h;
    forn(i, w){
        forn(y, h){
            char r;
            cin>>r;
            if(r == '.'){
                psax[i][y] = 1; psay[i][y] = 1;
                if(i) psay[i][y] += psay[i-1][y];
                if(y) psax[i][y] += psax[i][y-1];
            }
            else{
                psax[i][y] = 0;
                psay[i][y] = 0;
            }
            for(int lx = psax[i][y], ly = 1, j = i; j > i - psay[i][y]; j--, lx = min(lx, psax[j][y]), ly++)
                ans = max(ans, (lx * 2) + (2 * ly));
        }
    }
    cout<<ans - 1<<endl;
}