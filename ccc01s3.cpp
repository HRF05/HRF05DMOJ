#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
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
const int MAX = 3e2;
int n = 0, ans = 0;
pair<char, char> road[MAX];
vector<pii> adj[MAX];
bool bfs(int i){
    bool vis[30]{0};
    queue<int> q; q.push(0);
    while(!q.empty()){
        int nd = q.front(); q.pop();
        vis[nd] = 1;
        for(auto ed : adj[nd]){
            if(ed.s == i || vis[ed.f]) continue;
            q.push(ed.f);
        }
    }
    return !vis[1];
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    while(1){
        cin>>road[n].f>>road[n].s;
        if(road[n].f == '*') break;
        int a = road[n].f-'A', b = road[n].s-'A';
        adj[a].pb({b, n});
        adj[b].pb({a, n++});
    }
    for(int i = 0; i < n; i++){
        bool b = bfs(i);
        ans += b;
        if(b) cout<<road[i].f<<road[i].s<<endl;
    }
    cout<<"There are "<<ans<<" disconnecting roads."<<endl;
}