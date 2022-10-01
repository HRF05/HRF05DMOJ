#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#include <bits/stdc++.h>
#include <queue>
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
const int MAX = 1e4 + 5;
int n, ans = INT_MAX;
bool vis[MAX];
vector<int> adj[MAX];
void bfs(){
    queue<pii> q;
    q.push({0, 1});vis[0] = true;
    while(!q.empty()){
        pii u = q.front(); q.pop();
        if(!adj[u.f].size()) ans = min(ans, u.s);
        for(int ed : adj[u.f]){
            if(!vis[ed]){
                vis[ed] = 1; n--;
                q.push({ed, u.s + 1});
            }
        }
    }
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    su(n);
    for(int i = 0, a, d; i < n; i++){
        su(a);
        while(a--){
            su(d);
            adj[i].pb(--d);
        }
    }
    bfs();
    if(!--n) cout<<'Y'<<endl;
    else cout<<'N'<<endl;
    cout<<ans<<endl;
}