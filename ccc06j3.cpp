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
string s;
int ans;
map<char, int> m, mg;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    for(char i = 'a', c = 1, g = 0; i < 's'; i++, c == 3? (c = 1, g++) : c++) m[i] = c, mg[i] = g;
    for(char i = 't', c = 1, g = 0; i < 'z'; i++, c == 3? (c = 1, g++) : c++) m[i] = c, mg[i] = g;
    m['z'] = 4; m['s'] = 4; m[' '] = 1;
    mg['z'] = mg['y'], mg['s'] = mg['r'];
    while(1){
        cin>>s; ans = 0;
        if(s == "halt") break;
        for(int i = 0; i < s.length(); i++) ans += m[s[i]] + (i && mg[s[i]] == mg[s[i-1]]) * 2;
        cout<<ans<<endl;
    }
}