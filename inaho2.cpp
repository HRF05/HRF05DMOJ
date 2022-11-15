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
const int MAX = 1e7 + 5;
int n, q, c, in[10], sz[10], pre[MAX], bit[MAX];
void update(int L[10] , int dim, int idx, int val){
    if(dim == n){
        bit[idx] += val;
        return;
    }
    for(int i = L[dim]; i <= sz[dim]; i += i&-i) update(L, dim+1, idx+(i-1)*in[dim], val);
}
unsigned int query(int L[2][10], int dim, int idx){
    if(dim == n) return bit[idx];
    unsigned int ret = 0;
    for(int i = L[1][dim]; i > 0; i-=i&-i) ret += query(L, dim+1, idx+(i-1)*in[dim]);
    for(int i = L[0][dim]-1; i > 0; i-=i&-i) ret -= query(L, dim+1, idx+(i-1)*in[dim]);
    return ret;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>q; in[0] = 1;
    for(int i = 0; i < n; i++){
        cin>>sz[i];
        in[i+1] = sz[i] * in[i];
    }
    while(q--){
        cin>>c;
        if(c == 1){
            int L[10], val, T = 0;
            for(int i = 0; i < n; i++){
                cin>>L[i];
                T += (L[i]-1) * in[i];
            }
            cin>>val;
            update(L, 0, 0, val-pre[T]);
            pre[T] = val;
        }
        else{
            int L[2][10];
            for(int i = 0; i < n; i++) cin>>L[0][i];
            for(int i = 0; i < n; i++) cin>>L[1][i];
            cout<<query(L, 0, 0)<<endl;
        }
    }
}