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
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
map<char, int> rm;
int ans = 0;
string s;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    rm['I'] = 1; rm['V'] = 5; rm['X'] = 10; rm['L'] = 50; rm['C'] = 100; rm['D'] = 500; rm['M'] = 1000;
    cin>>s;
    for(int i = 0, a, b; i < s.length(); i+=2){
        a = s[i]-'0', b = rm[s[i+1]];
        if(i != s.length()-2 && b < rm[s[i+3]]) b *= -1;
        ans += b*a;
    }
    cout<<ans<<endl;
}