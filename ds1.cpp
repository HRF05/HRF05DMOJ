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
const int MAX = 1e5 + 5;
ll bits[MAX];
int bitf[MAX], n, m, a[MAX], f, s;
char c;
void updatesm(int nd, int vl){
    for(; nd <= n; nd += nd & -nd) bits[nd] += vl;
}
void updatefr(int nd, int vl){
    for(; nd < MAX; nd += nd & -nd) bitf[nd] += vl;
}
ll getsm(int nd){
    ll ret = 0;
    for(; nd > 0; nd -= nd & -nd) ret += bits[nd];
    return ret;
}
int getfr(int nd){
    int ret = 0;
    for(; nd > 0; nd -= nd & -nd) ret += bitf[nd];
    return ret;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        updatesm(i, a[i]);
        updatefr(a[i], 1);
    }
    while(m--){
        cin>>c>>f;
        if(c == 'C'){
            cin>>s;
            updatesm(f, s - a[f]);
            updatefr(s, 1);
            updatefr(a[f], -1);
            a[f] = s;
        }
        else if(c == 'S'){
            cin>>s;
            cout<<getsm(s) - getsm(f-1)<<endl;
        }
        else{
            cout<<getfr(f)<<endl;
        }
    }
}