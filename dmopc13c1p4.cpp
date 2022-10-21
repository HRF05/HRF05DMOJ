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
int qu, n, m;
pii st = {};
char g[55][55];
bool vis[55][55];
int bfs(){
    queue<tri> q;
    q.push({st.f, st.s, 0});
    vis[st.f][st.s] = 1;
    while(!q.empty()){
        tri u = q.front(); q.pop();
        if(u.t > 59) continue;
        else if(g[u.f][u.s] == 'W') return u.t;
        if(u.f+1 < n && !vis[u.f+1][u.s] && g[u.f+1][u.s] != 'X'){
            q.push({u.f+1, u.s, u.t+1});
            vis[u.f+1][u.s] = 1;
        }
        if(u.f && !vis[u.f-1][u.s] && g[u.f-1][u.s] != 'X'){
            q.push({u.f-1, u.s, u.t+1});
            vis[u.f-1][u.s] = 1;
        }
        if(u.s+1 < m && !vis[u.f][u.s+1] && g[u.f][u.s+1] != 'X'){
            q.push({u.f, u.s+1, u.t+1});
            vis[u.f][u.s+1] = 1;
        }
        if(u.s && !vis[u.f][u.s-1] && g[u.f][u.s-1] != 'X'){
            q.push({u.f, u.s-1, u.t+1});
            vis[u.f][u.s-1] = 1;
        }
    }
    return -1;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>qu;
    while(qu--){
        cin>>m>>n;
        for(int i = 0; i < n; i++){
            for(int y = 0; y < m; y++){
                cin>>g[i][y];
                if(g[i][y] == 'C') st = {i, y};
                vis[i][y] = 0;
            }
        }
        int t = bfs();
        if(t == -1) cout<<"#notworth"<<endl;
        else cout<<t<<endl;
    }
}