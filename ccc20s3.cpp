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
ll mod[2] = {(ll)1e9 + 7, (ll)1e9 + 9}, b[2] = {31, 37};
int ans = 0;
ll hsh[2] = {0, 0}, bp[2] = {1, 1};
string n, h;
map<pll, bool> s;
int frn[26], frh[26];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>h;
    for(int i = 0; i < n.size(); i++){
        frn[n[i] - 'a']++;
        frh[h[i] - 'a']++;
        for(int y = 0; y < 2; y++){
            hsh[y] = hsh[y] * b[y] + h[i] - 'a' + 1;
            hsh[y] %= mod[y];
            if(i) bp[y] *= b[y];
            bp[y] %= mod[y];
        }
    }
    for(int i = n.size() - 1; i < h.size(); i++){
        bool B = false;
        if(i - (int)n.size() >= 0){
            frh[h[i-(int)n.size()] - 'a']--;
            frh[h[i] - 'a']++;
            for(int y = 0; y < 2; y++){
                hsh[y] -= (h[i-n.size()] - 'a' + 1) * bp[y];
                hsh[y] = hsh[y] * b[y] + h[i] - 'a' + 1;
                hsh[y] = (hsh[y] % mod[y] + mod[y]) % mod[y];
            }
            
        }
        for(int y = 0; y < 26; y++){
            if(frn[y] != frh[y]){
                B = true;
            }
        }
        if(!B && !s[mp(hsh[0], hsh[1])]){
            s[mp(hsh[0], hsh[1])] = true;
            ans++;
        }
    }
    cout<<ans<<endl;
}