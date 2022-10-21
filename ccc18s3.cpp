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
const int MAX = 1e2 + 5;
int n, m, a, b, dist[MAX][MAX]; vector<pii> ex;
char gr[MAX][MAX];
bool vis[MAX][MAX] { 0 };
void bfs(){
    if(vis[a][b]) return;
    deque<pii> q;
    dist[a][b] = 0;
    q.pb({a, b});
    while(!q.empty()){
        pii u = q.front(); q.pop_front();
        int i = u.f, y = u.s;
        if(gr[i][y] == 'R'){
            if(!vis[i][y+1] && dist[i][y] < dist[i][y+1]){
                q.pf({i, y+1});
                dist[i][y+1] = dist[i][y];
                vis[i][y+1] = 1;
            }
            continue;
        }
        else if(gr[i][y] == 'L'){
            if(!vis[i][y-1] && dist[i][y] < dist[i][y-1]){
                q.pf({i, y-1});
                dist[i][y-1] = dist[i][y];
                vis[i][y-1] = 1;
            }
            continue;
        }
        else if(gr[i][y] == 'U'){
            if(!vis[i-1][y] && dist[i][y] < dist[i-1][y]){
                q.pf({i-1, y});
                dist[i-1][y] = dist[i][y];
                vis[i-1][y] = 1;
            }
            continue;
        }
        else if(gr[i][y] == 'D'){
            if(!vis[i+1][y] && dist[i][y] < dist[i+1][y]){
                q.pf({i+1, y});
                dist[i+1][y] = dist[i][y];
                vis[i+1][y] = 1;
            }
            continue;
        }
        if(!vis[i+1][y] && dist[i][y] + 1 < dist[i+1][y]){
            dist[i+1][y] = dist[i][y] + 1;
            q.pb({i+1, y});
        }
        if(!vis[i-1][y] && dist[i][y] + 1 < dist[i-1][y]){
            dist[i-1][y] = dist[i][y] + 1;
            q.pb({i-1, y});
        }
        if(!vis[i][y+1] && dist[i][y] + 1 < dist[i][y+1]){
            dist[i][y+1] = dist[i][y] + 1;
            q.pb({i, y+1});
        }
        if(!vis[i][y-1] && dist[i][y] + 1 < dist[i][y-1]){
            dist[i][y-1] = dist[i][y] + 1;
            q.pb({i, y-1});
        }
    }
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int y = 1; y <= m; y++){
            cin>>gr[i][y]; dist[i][y] = INT_MAX;
            if(gr[i][y] == 'W') vis[i][y] = 1;
            else if(gr[i][y] == '.') ex.pb({i, y});
            else if(gr[i][y] == 'S'){a = i, b = y; gr[i][y] = '.';}
        }
    }
    for(int i = 1; i <= n; i++){
        for(int y = 1; y <= m; y++){
            if(gr[i][y] == 'C'){
                int j = y+1;
                while(gr[i][j] != 'W'){
                    if(gr[i][j] == '.') vis[i][j] = 1;
                    j++;
                }
                j = y-1;
                while(gr[i][j] != 'W'){
                    if(gr[i][j] == '.') vis[i][j] = 1;
                    j--;
                }
                j = i+1;
                while(gr[j][y] != 'W'){
                    if(gr[j][y] == '.') vis[j][y] = 1;
                    j++;
                }
                j = i-1;
                while(gr[j][y] != 'W'){
                    if(gr[j][y] == '.') vis[j][y] = 1;
                    j--;
                }
                vis[i][y] = 1;
            }
        }
    }
    bfs();
    for(auto rt : ex) cout<<(dist[rt.f][rt.s] == INT_MAX? -1 : dist[rt.f][rt.s])<<endl;
}