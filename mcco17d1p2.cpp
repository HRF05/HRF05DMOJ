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
const int MAX = 2e5 + 5;
int n, k, q;
struct node{
    int l, r; ll ma, lazy;
}seg[MAX*4];
void build(int l, int r, int idx){
    seg[idx].l = l; seg[idx].r = r; seg[idx].lazy = seg[idx].ma = 0;
    if(l == r) return;
    int mid = (l+r)/2;
    build(l, mid, idx*2); build(mid+1, r, idx*2+1);
}
void pushup(int idx){
    if(seg[idx].r-seg[idx].l){
        seg[idx*2].ma += seg[idx].lazy;
        seg[idx*2+1].ma += seg[idx].lazy;
        seg[idx*2].lazy += seg[idx].lazy;
        seg[idx*2+1].lazy += seg[idx].lazy;
    }
    seg[idx].lazy = 0;
}
void update(int l, int r, int idx, int val){
    if(seg[idx].l == l && seg[idx].r == r){
        seg[idx].ma += val; seg[idx].lazy += val; return;
    }
    if(seg[idx].lazy) pushup(idx);
    int mid = (seg[idx].l+seg[idx].r)/2;
    if(r <= mid) update(l, r, idx*2, val);
    else if(l > mid) update(l, r, idx*2+1, val);
    else {update(l, mid, idx*2, val); update(mid+1, r, idx*2+1, val);}
    seg[idx].ma = max(seg[idx*2].ma, seg[idx*2+1].ma);
}
ll query(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r == r) return seg[idx].ma;
    if(!seg[idx].l) return 0;
    if(seg[idx].lazy) pushup(idx);
    int mid = (seg[idx].l+seg[idx].r)/2;
    if(r <= mid) return query(l, r, idx*2);
    if(l > mid) return query(l, r, idx*2+1);
    return max(query(l, mid, idx*2), query(mid+1, r, idx*2+1));
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>k>>q;
    build(1, n, 1); 
    while(q--){
        int c, a, b; cin>>c>>a>>b; a++;
        if(c) cout<<query(a, b+1, 1)<<endl;
        else update(max(1, a-k+1), a, 1, b);
    }
}