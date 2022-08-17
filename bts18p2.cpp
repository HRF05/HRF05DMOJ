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
string s;
const int MX = 1e6 + 5;
int q, psa[MX][26];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    getline(cin, s);
    for(int i = 0; i < s.length(); i++){
        if(s[i] != ' ') psa[i][s[i] - 'a']++;
        if(i) for(int y = 0; y < 26; y++) psa[i][y] += psa[i-1][y];
    }
    for(int i = s.length(); i < MX; i++){
        for(int y = 0; y < 26; y++) psa[i][y] += psa[i-1][y];
    }
    cin>>q;
    for(int i = 0, a, b; i < q; i++){
        char c;
        cin>>a>>b>>c;
        cout<<psa[b-1][c-'a'] - ((a-1)? psa[a-2][c-'a'] : 0)<<endl;
    }
}