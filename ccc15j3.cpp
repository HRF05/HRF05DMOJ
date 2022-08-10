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
// vowels : a e i o u
// consonants : b c d f g h j k l m n p q r s t v w x y z
map<char, bool> cons;
string s;
string ans;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cons['b'] = true; cons['c'] = true;cons['d'] = true;cons['f'] = true;cons['g'] = true;cons['h'] = true;cons['j'] = true;
    cons['k'] = true;cons['l'] = true;cons['m'] = true;cons['n'] = true;cons['p'] = true;cons['q'] = true;cons['r'] = true;
    cons['s'] = true;cons['t'] = true;cons['v'] = true;cons['w'] = true;cons['x'] = true;cons['y'] = true;cons['z'] = true;
    cin>>s;
    for(int i = 0; i < s.length(); i++){
        ans += s[i];
        if(cons[s[i]]){
            char t = s[i] - 1;
            char r = s[i] + 1;
            while((cons[r] || r > 'z') && cons[t]){
                r++;t--;
            }
            if(!cons[t]){
                ans += t;
            }
            else{
                ans += r;
            }
            char nxt = s[i] + 1;
            while(!cons[nxt]) nxt++;
            if(s[i] == 'z') nxt = 'z';
            ans += nxt;
        }
    }
    cout<<ans<<endl;
}