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
int n, n1, n2, v = 0;
map<string, vector<string>> m;
map<string, vector<string>> mb;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){
        string a, b;
        cin>>a>>b;
        m[a].pb(b);
    }
    cin>>n1;
    for(int i = 0; i < n1; i++){
        string a, b;
        cin>>a>>b;
        mb[a].pb(b);
    }
    cin>>n2;
    for(int i = 0; i < n2; i++){
        string a[3];
        cin>>a[0]>>a[1]>>a[2];
        for(int y = 0; y < 3; y++){
            string b, c;
            if(y == 0) b = a[1], c = a[2];
            if(y == 1) b = a[0], c = a[2];
            if(y == 2) b = a[0], c = a[1];
            for(int i = 0; i < m[a[y]].size(); i++){
                if(m[a[y]][i] != b && m[a[y]][i] != c){
                    v++;
                }
            }
            for(int i = 0; i < mb[a[y]].size(); i++){
                if(mb[a[y]][i] == b || mb[a[y]][i] == c){
                    v++;
                }
            }
        }
        
    }
    cout<<v<<endl;
}