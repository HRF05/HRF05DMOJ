#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
const int base = 31, mod = 1e9 + 7;
string a, b;
map<ll, bool> m;
ll bl, h = 0, bp = 1;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>a>>b;
    bl = b.length();
    for(int i = 0; i < bl; i++){
        if(i) bp = (bp * base) % mod;
        h = h * base + b[i];
        h = (h % mod + mod) % mod;
    }
    m[h] = 1;
    for(int i = 0; i < bl-1; i++){
        h -= bp * b[i];
        h = h * base + b[i];
        h = (h % mod + mod) % mod;
        m[h] = 1;
    }
    h = 0;
    for(int i = 0; i < a.length(); i++){
        if(i >= b.length()){
            if(m[h]){
                cout<<"yes"<<endl;
                return 0;
            }
            h -= bp * a[i-b.length()];
            h = h * base + a[i];
        }
        else h = h * base + a[i];
        h = (h % mod + mod) % mod;
    }
    if(m[h]) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}