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
ll toBTen(ll num, int startBase){
    int cur = 0, lng = 1; ll ret = 0;
    while(lng <= num){
        int t = (num/lng)%10;
        ret += t * pow(startBase, cur);
        cur++; lng *= 10;
    }
    return ret;
}
ll cnv(ll num, int startBase, int base){
    if(startBase != 10) num = toBTen(num, startBase);
    int up = log(num)/log(base); ll ret = 0;
    for(int i = up, k = pow(base, up); i >= 0; i--, k /= base){
        while(num-k >= 0){
            num -= k; ret += pow(10, i);
        }
    }
    return ret;
}
bool palin(ll num){
    vi nm;
    while(num > 0){
        nm.pb(num%10); num /= 10;
    }
    for(int i = 0; i < nm.size(); i++){
        if(nm[i] != nm[nm.size()-1-i]) return 0;
    }
    return 1;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    for(int i = 0, a, b, c, d, e; i < 5; i++){
        cin>>a>>b>>c>>d>>e;
        ll num = toBTen(a, b) * toBTen(c, d);
        cout<<cnv(num, 10, e)<<endl;
    }
}