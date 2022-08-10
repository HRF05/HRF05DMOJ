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
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define pb push_back
#define mp make_pair
#define INF 2e18
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int i, y, j, n;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    forn(i, n){
        string s;
        vector<int> C;
        int c, l = INT_MAX;
        cin>>s>>c;
        for(y = 0; y < s.length() && c > 0; y++){
            if((y == s.length() - 1 && s[y] > l) || (y < s.length() - 1 && s[y] > s[y + 1])){
                C.push_back(s[y] - 48);
                if(s[y] < l) l = s[y]; 
                s.erase(s.begin() + y);
                c--;
                y = max(-1, y-2);
            }
        }
        cout<<s;
        sort(C.begin(), C.end());
        for(y = 0; y < C.size(); y++){
            cout<<C[y];
        }
        cout<<endl;
    }
}