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
const int MAX = 1<<20;
int n, q;
struct node{
    int win, i, sk;
} seg[MAX*4];
void build(int l, int r, int idx){
    if(l == r){
        cin>>seg[idx].sk;
        seg[idx].win = 0;
        seg[idx].i = l;
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, idx*2); build(mid+1, r, idx*2+1);
    if(seg[idx*2].sk > seg[idx*2+1].sk){
        seg[idx].sk = seg[idx*2].sk;
        seg[idx].win = seg[idx*2].win + 1;
        seg[idx].i = seg[idx*2].i;
    }
    else{
        seg[idx].sk = seg[idx*2+1].sk;
        seg[idx].win = seg[idx*2+1].win + 1;
        seg[idx].i = seg[idx*2+1].i;
    }
}
void update(int l, int r, int idx, int pos, int val){
    if(l == r){
        seg[idx].sk = val;
        seg[idx].i = pos;
        seg[idx].win = 0;
        return;
    }
    int mid = (l + r) / 2;
    pos <= mid? update(l, mid, idx*2, pos, val) : update(mid+1, r, idx*2+1, pos, val);
    if(seg[idx*2].sk > seg[idx*2+1].sk){
        seg[idx].sk = seg[idx*2].sk;
        seg[idx].win = seg[idx*2].win + 1;
        seg[idx].i = seg[idx*2].i;
    }
    else{
        seg[idx].sk = seg[idx*2+1].sk;
        seg[idx].win = seg[idx*2+1].win + 1;
        seg[idx].i = seg[idx*2+1].i;
    }
}
int query(int l, int r, int idx, int pos){
    if(seg[idx].i == pos) return seg[idx].win;
    int mid = (l + r) / 2;
    return pos <= mid? query(l, mid, idx*2, pos) : query(mid+1, r, idx*2+1, pos);
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>q; n = 1<<n;
    build(1, n, 1);
    while(q--){
        char c; cin>>c;
        if(c == 'R'){
            int x, val; cin>>x>>val;
            update(1, n, 1, x, val);
        }
        else if(c == 'W') cout<<seg[1].i<<endl;
        else{
            int k; cin>>k;
            cout<<query(1, n, 1, k)<<endl;
        }
    }
}