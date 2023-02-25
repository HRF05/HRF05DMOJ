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
struct node{
    int l, r; ll an;
}seg[MAX*4];
void build(int l, int r, int idx){
    seg[idx].l = l; seg[idx].r = r;
    if(l == r){ cin>>seg[idx].an; return; }
    int mid = (l + r) / 2;
    build(l, mid, idx*2); build(mid+1, r, idx*2+1);
    seg[idx].an = seg[idx*2].an & seg[idx*2+1].an;
}
void update(int x, ll val, int idx){
    if(seg[idx].l == seg[idx].r){ seg[idx].an = val; return; }
    int mid = (seg[idx].l + seg[idx].r) / 2;
    x <= mid? update(x, val, idx*2) : update(x, val, idx*2+1);
    seg[idx].an = seg[idx*2].an & seg[idx*2+1].an;
}
ll query(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r == r) return seg[idx].an;
    int mid = (seg[idx].l + seg[idx].r) / 2;
    if(r <= mid) return query(l, r, idx*2);
    if(l > mid) return query(l, r, idx*2+1);
    return query(l, mid, idx*2) & query(mid+1, r, idx*2+1);
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    build(1, n, 1);
    while(q--){
        char c; cin>>c;
        if(c == 'U'){
            int x; ll val; cin>>x>>val;
            update(x, val, 1);
        }
        else{
            int x, y; ll val; cin>>x>>y>>val;
            cout<<(val & query(x, y, 1))<<endl;
        }
    }
}