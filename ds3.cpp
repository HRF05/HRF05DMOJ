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
const int MAX = 1e5 + 5;
int n, q;
struct seg{
    int l, r, gcd, fr, mi;
} tre[MAX*4];
void build(int l, int r, int idx){
    tre[idx].l = l, tre[idx].r = r;
    if(l == r){cin>>tre[idx].gcd; tre[idx].mi = tre[idx].gcd; tre[idx].fr = 1; return;}
    int mid = (l + r) / 2;
    build(l, mid, idx*2); build(mid+1, r, idx*2+1);
    tre[idx].mi = min(tre[idx*2].mi, tre[idx*2+1].mi);
    tre[idx].gcd = __gcd(tre[idx*2].gcd, tre[idx*2+1].gcd);
    tre[idx].fr = (tre[idx].gcd == tre[idx*2].gcd? tre[idx*2].fr : 0) + (tre[idx].gcd == tre[idx*2+1].gcd? tre[idx*2+1].fr : 0);
}
void update(int x, int val, int idx){
    if(tre[idx].l == tre[idx].r){ tre[idx].gcd = tre[idx].mi = val; return; }
    int mid = (tre[idx].r + tre[idx].l) / 2;
    x <= mid? update(x, val, idx*2) : update(x, val, idx*2+1);
    tre[idx].mi = min(tre[idx*2].mi, tre[idx*2+1].mi);
    tre[idx].gcd = __gcd(tre[idx*2].gcd, tre[idx*2+1].gcd);
    tre[idx].fr = (tre[idx].gcd == tre[idx*2].gcd? tre[idx*2].fr : 0) + (tre[idx].gcd == tre[idx*2+1].gcd? tre[idx*2+1].fr : 0);
}
int querym(int l, int r, int idx){
    if(tre[idx].l == l && tre[idx].r == r) return tre[idx].mi;
    int mid = (tre[idx].l + tre[idx].r) / 2;
    if(r <= mid) return querym(l, r, idx*2);
    if(l > mid) return querym(l, r, idx*2+1);
    return min(querym(l, mid, idx*2), querym(mid+1, r, idx*2+1));
}
int queryg(int l, int r, int idx){
    if(tre[idx].l == l && tre[idx].r == r) return tre[idx].gcd;
    int mid = (tre[idx].l + tre[idx].r) / 2;
    if(r <= mid) return queryg(l, r, idx*2);
    if(l > mid) return queryg(l, r, idx*2+1);
    return __gcd(queryg(l, mid, idx*2), queryg(mid+1, r, idx*2+1));
}
int queryf(int l, int r, int val, int idx){
    if(tre[idx].l == l && tre[idx].r == r) return tre[idx].fr * (tre[idx].gcd == val);
    int mid = (tre[idx].l + tre[idx].r) / 2;
    if(r <= mid) return queryf(l, r, val, idx*2);
    if(l > mid) return queryf(l, r, val, idx*2+1);
    return queryf(l, mid, val, idx*2) + queryf(mid+1, r, val, idx*2+1);
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>q; build(1, n, 1);
    while(q--){
        char c; int l, r; cin>>c>>l>>r;
        if(c == 'C') update(l, r, 1);
        else if(c == 'M') cout<<querym(l, r, 1)<<endl;
        else if(c == 'G') cout<<queryg(l, r, 1)<<endl;
        else cout<<queryf(l, r, queryg(l, r, 1), 1)<<endl;
    }
}