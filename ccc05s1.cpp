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
map<char, int> m;
string s;
int nm[100], ind = 0, t;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    m['A'] = 2; m['B'] = 2; m['C'] = 2;
    m['D'] = 3; m['E'] = 3; m['F'] = 3;
    m['G'] = 4; m['H'] = 4; m['I'] = 4;
    m['J'] = 5; m['K'] = 5; m['L'] = 5;
    m['M'] = 6; m['N'] = 6; m['O'] = 6;
    m['P'] = 7; m['Q'] = 7; m['R'] = 7; m['S'] = 7;
    m['T'] = 8; m['U'] = 8; m['V'] = 8;
    m['W'] = 9; m['X'] = 9; m['Y'] = 9; m['Z'] = 9;
    
    cin>>t;
    getline(cin, s);
    while(t--){
        ind = 0;
        getline(cin, s);
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '-') continue;
            if(s[i] >= '0' && s[i] <= '9'){
                nm[ind++] = s[i] - '0';
            }
            else{
                nm[ind++] = m[s[i]];
            }
        }
        for(int i = 0; i < 10; i++){
            cout<<nm[i];
            if(i == 2 || i == 5) cout<<'-';
        }
        cout<<endl;
    }
    
}