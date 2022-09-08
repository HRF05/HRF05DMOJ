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
int ic = 0, ans = 0; pii curp = mp(0, 0);
map<char, pii> m;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    for(char i = 'A'; ic < 5; i += 6, ic++){
        int yc = 0;
        for(char y = i; yc < 6 && y <= 'Z'; y++, yc++){
            m[y] = mp(yc, ic);
        }
    }
    m[' '] = mp(2, 4); m['-'] = mp(3, 4); m['.'] = mp(4, 4); m['e'] = mp(5, 4);
    getline(cin, s);
    for(auto i : s){
        ans += abs(m[i].f - curp.f) + abs(m[i].s - curp.s);
        curp = m[i];
    }
    ans += abs(m['e'].f - curp.f) + abs(m['e'].s - curp.s);
    cout<<ans<<endl;
}