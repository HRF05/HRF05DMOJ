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
const int MAX = 1e3 + 5;
int n, m;
pii s, e;
char c;
bool vis[MAX][MAX];
int bfs(){
    queue<tri> q;
    q.push({s.f, s.s, 0});
    while(!q.empty()){
        tri u = q.front(); q.pop();
        if(u.f == e.f && u.s == e.s) return u.t;
        if(vis[u.f+1][u.s]){
            q.push({u.f+1, u.s, u.t+1});
            vis[u.f+1][u.s] = 0;
        }
        if(vis[u.f-1][u.s]){
            q.push({u.f-1, u.s, u.t+1});
            vis[u.f-1][u.s] = 0;
        }
        if(vis[u.f][u.s+1]){
            q.push({u.f, u.s+1, u.t+1});
            vis[u.f][u.s+1] = 0;
        }
        if(vis[u.f][u.s-1]){
            q.push({u.f, u.s-1, u.t+1});
            vis[u.f][u.s-1] = 0;
        }
    }
    return 0;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int y = 1; y <= m; y++){
            cin>>c;
            if(c != 'X') vis[i][y] = 1;
            if(c == 's') s = {i, y};
            if(c == 'e') e = {i, y};
        }
    }
    cout<<bfs()-1<<endl;
}