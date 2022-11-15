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
const int MAX = 1050;
int t, n, bit[MAX][MAX];
void update(int x, int y, int val){
    x++;y++;
    for(int i = x; i <= n; i+=i&-i){
        for(int j = y; j <= n; j+=j&-j) bit[i][j] += val;
    }
}
int get(int x, int y){
    int ret = 0; x++; y++;
    for(int i = x; i > 0; i-=i&-i){
        for(int j = y; j > 0; j -= j&-j) ret += bit[i][j];
    }
    return ret;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>t>>n;
    while(1){
        cin>>t;
        if(t == 3) break;
        if(t-1){
            int x, y, x1, y1; cin>>x>>y>>x1>>y1;
            cout<<get(x1, y1) + get(x-1, y-1) - get(x-1, y1) - get(x1, y-1)<<endl;
        }
        else{
            int x, y, val; cin>>x>>y>>val;
            update(x, y, val);
        }
    }
}