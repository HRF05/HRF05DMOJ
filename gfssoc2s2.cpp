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
int n, t, a[1001];
string out[1001], s[1001];
vector<tri> ans;
bool lexi(string I, string Y){ // a < b -> true
    for(int i = 0; i < min(I.length(), Y.length()); i++){
        if(I[i] < Y[i]) return true;
        else if(I[i] > Y[i]) return false;
    }
    if(I.length() < Y.length()) return false;
    else return true;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>t;
    for(int i = 0; i < n; i++){
        cin>>s[i]>>a[i];
    }
    for(int i = 0; i < n; i++){
        for(int y = 0; y < i; y++){
            if(i == y) continue;
            for(int j = 0; j < y; j++){
                if(j == y || j == i) continue; 
                ans.pb({i, y, j});
            }
        }
    }
    int ind = 0;
    for(int i = 0; i < ans.size(); i++){
        int I = ans[i].f, Y = ans[i].s, J = ans[i].t;
        if(a[I] + a[Y] + a[J] > t){
            continue;
        } 
        string st[3];
        st[0] = s[I]; st[1] = s[Y]; st[2] = s[J];
        sort(st, st + 3, lexi);
        out[ind] = "";
        out[ind] += st[0] + " " + st[1] + " " + st[2];
        ind++;
    }
    
    sort(out, out + ind, lexi);
    for(int i = 0; i < ind; i++){
        cout<<out[i]<<endl;
    }
}