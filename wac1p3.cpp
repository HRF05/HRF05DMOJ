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
const int MAX = 1e5 + 5;
int n, m, k, f[MAX], lvn = 0, prnt[MAX];
pii lv[MAX];
vi adj[MAX];
bool vis[MAX];
void dfs(int nd, int dpth){
    for(auto ed : adj[nd]){
        prnt[ed] = nd;
        dfs(ed, dpth + 1);
    }
    if(!adj[nd].size()) lv[lvn++] = mp(dpth, nd);
}
bool srt(pii a, pii b){ return a.f > b.f; }
int main(){
    su(n);su(m);su(k);
    for(int i = 2, a; i <= n; i++){
        su(a);
        adj[a].pb(i);
    }
    dfs(1, 0);
    sort(lv, lv + lvn, srt);
    for(int i = 0; i < k && i < lvn; i++){
        for(int y = lv[i].s; y > 0; y = prnt[y]){
            if(!vis[y]){
                f[i]++;
                vis[y] = true;
            }
            else break;
        }
    }
    sort(f, f + min(k, lvn), greater<int>());
    for(int i = 0; i < m - 1; i++){
        cout<<f[i % k]<<' ';
    }
    cout<<f[(m-1)%k]<<endl;
}