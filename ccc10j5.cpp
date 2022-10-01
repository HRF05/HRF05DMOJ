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
int a, b, c, d;
bool vis[8][8];
void bfs(){
    queue<tri> q; vis[a][b] = 1;
    q.push({a, b, 0});
    while(!q.empty()){
        tri u = q.front(); q.pop();
        vis[u.f][u.s] = 1;
        if(u.f == c && u.s == d){
            cout<<u.t<<endl;
            exit(0);
        }
        if(u.f + 1 < 8 && u.s + 2 < 8 && !vis[u.f+1][u.s+2]) q.push({u.f+1, u.s+2, u.t+1});
        if(u.f + 1 < 8 && u.s - 2 >= 0 && !vis[u.f+1][u.s-2]) q.push({u.f+1, u.s-2, u.t+1});
        if(u.f + 2 < 8 && u.s + 1 < 8 && !vis[u.f+2][u.s+1]) q.push({u.f+2,u.s+1, u.t+1});
        if(u.f + 2 < 8 && u.s - 1 >= 0 && !vis[u.f+2][u.s-1]) q.push({u.f+2,u.s-1, u.t+1});
        if(u.f - 1 >= 0 && u.s + 2 < 8 && !vis[u.f-1][u.s+2]) q.push({u.f-1, u.s+2, u.t+1});
        if(u.f - 1 >= 0 && u.s - 2 >= 0 && !vis[u.f-1][u.s-2]) q.push({u.f-1, u.s-2, u.t+1});
        if(u.f - 2 >= 0 && u.s + 1 < 8 && !vis[u.f-2][u.s+1]) q.push({u.f-2, u.s+1, u.t+1});
        if(u.f - 2 >= 0 && u.s - 1 >= 0 && !vis[u.f-2][u.s-1]) q.push({u.f-2, u.s-1, u.t+1});
    }
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>a>>b>>c>>d;
    a--;b--;c--;d--;
    bfs();
}