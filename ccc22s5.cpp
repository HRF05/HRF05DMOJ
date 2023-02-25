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
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
const int MAX = 2e5 + 5;
ll dp[MAX][3]{0}; int n, cost[MAX]{0}; // 0 no influence with pr, 1 inclfence pr, 2 pr influence
vi adj[MAX];
bool vis[MAX]{0};
void dfs(int nd, int pr){
    ll ret[5]{0};
    ret[3] = ret[4] = INT_MAX;
    for(auto ed : adj[nd]){
        if(ed == pr) continue;
        dfs(ed, nd);
        for(int i = 0; i < 3; i++) ret[i] += dp[ed][i];
        ret[3] = min(ret[3], dp[ed][1] - dp[ed][0]);
        ret[4] = min(ret[4], dp[ed][1] - dp[ed][2]);
    }
    if(vis[nd]){
        dp[nd][1] = ret[2]+cost[nd]+ret[4];
        dp[nd][0] = ret[0]+ret[3];
        dp[nd][2] = min(ret[0], cost[nd]+ret[2]);
    }
    else{
        dp[nd][0] = ret[0];
        dp[nd][1] = ret[2]+cost[nd];
        dp[nd][2] = ret[0];
    }
    dp[nd][0] = min(dp[nd][0], dp[nd][1]);
    dp[nd][2] = min(dp[nd][2], dp[nd][0]);
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 1, a, b; i < n; i++){
        cin>>a>>b;
        adj[a].pb(b); adj[b].pb(a);
    }
    for(int i = 1; i <= n; i++){
        char c; cin>>c;
        vis[i] = c!='Y';
    }
    for(int i = 1; i <= n; i++) cin>>cost[i];
    dfs(1, 0);
    cout<<dp[1][0]<<endl;
}