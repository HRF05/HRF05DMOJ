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
const int MAX = 4e3 * 4e3 + 5;
int n, m, head[MAX], egt = 0;
bitset<MAX> vis;
struct edgd{
    int to, nxt;
} edges[MAX];
void makee(int fr, int to){
    edges[egt].to = to;
    edges[egt].nxt = head[fr];
    head[fr] = egt++;
}
bool can_escape(int M, int N, vector<vector<int>> v){
    memset(head, -1, sizeof(head));
    n = M, m = N;
    for(int i = 1; i <= n; i++){
        for(int y = 1; y <= m; y++){
            makee(i * y, v[i][y]);
        }
    }
    queue<int> q;
    q.push(1); vis[1] = 1;
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int i = head[u]; i+1; i = edges[i].nxt){
            if(!vis[edges[i].to]){
                vis[edges[i].to] = 1;
                q.push(edges[i].to);
            }
        }
    }
    return vis[n*m];
}