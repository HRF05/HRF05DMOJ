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
const int MAX = 55;
int r, c, ans = 0;
char g[MAX][MAX];
bool vis[MAX][MAX];
vector<pii> m;
bool bfs(pii st){
    queue<pii> q;
    q.push(st);
    while(!q.empty()){
        pii u = q.front(); q.pop();
        if(!vis[u.f+1][u.s]){
            q.push({u.f+1, u.s});
            vis[u.f+1][u.s] = 1;
        }
        if(!vis[u.f-1][u.s]){
            q.push({u.f-1, u.s});
            vis[u.f-1][u.s] = 1;
        }
        if(!vis[u.f][u.s+1]){
            q.push({u.f, u.s+1});
            vis[u.f][u.s+1] = 1;
        }
        if(!vis[u.f][u.s-1]){
            q.push({u.f, u.s-1});
            vis[u.f][u.s-1] = 1;
        }
    }
    return 1;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>r>>c;
    for(int i = 1; i <= r; i++){
        for(int y = 1; y <= c; y++){
            cin>>g[i][y];
            if(g[i][y] == 'M') m.pb({i, y});
            else if(g[i][y] == '#') vis[i][y] = 1;
        }
    }
    for(pii st : m){
        if(!vis[st.f][st.s]) ans += bfs(st);
    }
    cout<<ans<<endl;
}