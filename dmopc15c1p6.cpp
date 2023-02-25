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
#define int ll
const int MAX = 2e5 + 5;
int n, q, m;
struct node{
    int l, r, sum, lazy;
}seg[MAX*4];
void build(int l, int r, int idx){
    seg[idx].l = l; seg[idx].r = r; seg[idx].lazy = 0;
    if(l == r){
        cin>>seg[idx].sum; seg[idx].sum %= m; return;
    }
    int mid = (l + r) / 2;
    build(l, mid, idx*2); build(mid+1, r, idx*2+1);
    seg[idx].sum = (seg[idx*2].sum + seg[idx*2+1].sum) % m;
}
void get(int idx){
    if(seg[idx].r - seg[idx].l){
        seg[idx*2].lazy += seg[idx].lazy;
        seg[idx*2+1].lazy += seg[idx].lazy;
        seg[idx*2].lazy %= m;
        seg[idx*2+1].lazy %= m;
        seg[idx*2].sum += (seg[idx*2].r-seg[idx*2].l+1)*seg[idx].lazy;
        seg[idx*2].sum %= m;
        seg[idx*2+1].sum += (seg[idx*2+1].r-seg[idx*2+1].l+1)*seg[idx].lazy;
        seg[idx*2+1].sum %= m;
    }
    seg[idx].lazy = 0;
}
void update(int l, int r, int idx, int val){
    if(seg[idx].l == l && seg[idx].r == r){
        seg[idx].sum += (r-l+1) * val; seg[idx].lazy += val; 
        seg[idx].sum %= m; seg[idx].lazy %= m; return;
    }
    if(seg[idx].lazy) get(idx);
    int mid = (seg[idx].l + seg[idx].r) / 2;
    if(r <= mid) update(l, r, idx*2, val);
    else if(l > mid) update(l, r, idx*2+1, val);
    else{
        update(l, mid, idx*2, val); update(mid+1, r, idx*2+1, val);
    }
    seg[idx].sum = (seg[idx*2].sum + seg[idx*2+1].sum) % m;
}
int query(int l, int r, int idx){
    if(seg[idx].l == l && seg[idx].r == r) return seg[idx].sum % m;
    if(seg[idx].lazy) get(idx);
    int mid = (seg[idx].l + seg[idx].r) / 2;
    if(r <= mid) return query(l, r, idx*2) % m;
    if(l > mid) return query(l, r, idx*2+1) % m;
    return (query(l, mid, idx*2) + query(mid+1, r, idx*2+1)) % m;
}
signed main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>m>>n>>q;
    build(1, n, 1);
    while(q--){
        int t; cin>>t;
        if(t == 1){
            int l, r, x; cin>>l>>r>>x;
            update(l, r, 1, x);
        }
        else{
            int l, r; cin>>l>>r;
            cout<<query(l, r, 1)<<endl;
        }
    }
}