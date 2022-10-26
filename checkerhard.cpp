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
const int MAX = 3e3;
int n, m, q, bit[MAX][MAX], pre[MAX][MAX];
void update(int r, int c, int val){
    for(int i = r; i <= n; i += i & -i){
        for(int y = c; y <= m; y += y & -y) bit[i][y] += val;
    }
}
ll query(int r, int c){
    ll ret = 0;
    for(int i = r; i; i -= i & -i){
        for(int y = c; y; y -= y & -y) ret += bit[i][y];
    }
    return ret;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    while(1){
        cin>>q;
        if(!q) break;
        else if(q == 1){
            int r, c, v; cin>>r>>c>>v;
            if((r + c) % 2) v *= -1;
            update(r, c, -pre[r][c] + v); pre[r][c] = v;
        }
        else{
            int r1, c1, r2, c2; cin>>r1>>c1>>r2>>c2;
            ll t = query(r2, c2) - query(r1-1, c2) - query(r2, c1-1) + query(r1-1, c1-1);
            if((r1 + c1) % 2) t *= -1;
            cout<<t<<endl;
        }
    }
}