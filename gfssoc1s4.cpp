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
const int MAX = 251;
int n, q, pre[MAX][MAX][MAX];
ll ans, bit[MAX][MAX][MAX];
char c;
void update(int x, int y, int z, int val){
    for(int i = x; i <= n; i += i&-i){
        for(int j = y; j <= n; j += j&-j){
            for(int k = z; k <= n; k += k&-k) bit[i][j][k] += val;
        }
    }
}
ll get(int x, int y, int z){
    ll ret = 0;
    for(int i = x; i; i -= i&-i){
        for(int j = y; j; j -= j&-j){
            for(int k = z; k; k -= k&-k) ret += bit[i][j][k];
        }
    }
    return ret;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    while(q--){
        cin>>c;
        if(c == 'C'){
            int x, y, z, val; cin>>x>>y>>z>>val;
            update(x, y, z, val-pre[x][y][z]);
            pre[x][y][z] = val;
        }
        else{
            int x, y, z, x1, y1, z1; cin>>x>>y>>z>>x1>>y1>>z1;
            x--;y--;z--;
            ans += get(x1, y1, z1) - get(x, y, z) + get(x1, y, z) + get(x, y1, z) + get(x, y, z1) - get(x1, y1, z) - get(x1, y, z1) - get(x, y1, z1);
        }
    }
    cout<<ans<<endl;
}