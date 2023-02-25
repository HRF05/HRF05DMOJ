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
struct tri {int first, second, t;bool operator<(const tri& T){return t > T.t;}};
#define f first
#define s second
#define pb push_back
#define pf push_front
#define mp make_pair
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
const int MAX = 1e4 + 5;
int ds[MAX], c, r, d;
bool de[MAX];
tri edg[MAX*10];
int find(int x){
    return ds[x] = x == ds[x]? x : find(ds[x]);
}
bool merge(int x, int y){
    x = find(x), y = find(y);
    if(x != y) return ds[x] = y;
    return 0;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>c>>r>>d;
    for(int i = 0; i < r; i++) cin>>edg[i].f>>edg[i].s>>edg[i].t;
    for(int i = 1; i <= c; i++) ds[i] = i;
    for(int i = 0, a; i < d; i++){
        cin>>a; de[a] = 1;
    }
    sort(edg, edg + r);
    for(int i = 0; i < r; i++){
        if(merge(edg[i].f, edg[i].s)){
            if(de[edg[i].f]) d--, de[edg[i].f] = 0;
            if(de[edg[i].s]) d--, de[edg[i].s] = 0;
            if(!d){
                cout<<edg[i].t<<endl; break;
            }
        }
    }
}