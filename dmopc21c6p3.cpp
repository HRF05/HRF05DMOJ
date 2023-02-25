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
struct tri {int first, second, t;bool operator<(const tri& T){return t < T.t;}};
#define f first
#define s second
#define pb push_back
#define pf push_front
#define mp make_pair
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
const int MAX = 1e3 + 5e2 + 5;
int n, m, k, dist[MAX][MAX];
vector<tri> ty;
void bfs(){
    queue<tri> q;
    for(auto ed : ty) q.push({ed.f, ed.s, k});
    while(!q.empty()){
        tri u = q.front(); q.pop();
        if(!u.t) continue;
        if(!dist[u.f+1][u.s]){
            dist[u.f+1][u.s] = dist[u.f][u.s];
            q.push({u.f+1, u.s, u.t-1});
        }
        if(!dist[u.f-1][u.s]){
            dist[u.f-1][u.s] = dist[u.f][u.s];
            q.push({u.f-1, u.s, u.t-1});
        }
        if(!dist[u.f][u.s+1]){
            dist[u.f][u.s+1] = dist[u.f][u.s];
            q.push({u.f, u.s+1, u.t-1});
        }
        if(!dist[u.f][u.s-1]){
            dist[u.f][u.s-1] = dist[u.f][u.s];
            q.push({u.f, u.s-1, u.t-1});
        }
    }
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    for(int i = 1; i <= n; i++){
        dist[i][0] = dist[i][m+1] = 1;
        for(int y = 1; y <= m; y++){
            dist[0][y] = dist[n+1][y] = 1;
            cin>>dist[i][y];
            if(dist[i][y]) ty.pb({i, y, dist[i][y]});
        }
    }
    sort(ty.begin(), ty.end());
    bfs();
    for(int i = 1; i <= n; i++){
        for(int y = 1; y <= m; y++) cout<<dist[i][y]<<" ";
        cout<<endl;
    }
}