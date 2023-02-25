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
const int MAX = 30;
int l, n, m, cur, ans = 0;
bool vis[MAX][MAX]{0};
vi re;
void dfs(int i, int y){
    vis[i][y] = 1; cur++;
    if(!vis[i+1][y]) dfs(i+1, y);
    if(!vis[i][y+1]) dfs(i, y+1);
    if(!vis[i-1][y]) dfs(i-1, y);
    if(!vis[i][y-1]) dfs(i, y-1);
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>l>>n>>m;
    for(int i = 1; i <= n; i++){
        for(int y = 1; y <= m; y++){
            char c; cin>>c;
            vis[i][y] = c == 'I';
        }
    }
    for(int i = 0; i <= m+1; i++) vis[0][i] = vis[n+1][i] = 1;
    for(int i = 0; i <= n+1; i++) vis[i][0] = vis[i][m+1] = 1;
    for(int i = 1; i <= n; i++){
        for(int y = 1; y <= m; y++){
            if(!vis[i][y]){
                cur = 0;
                dfs(i, y);
                re.pb(cur);
            }
        }
    }
    sort(re.begin(), re.end(), greater<int>());
    for(auto ed : re){
        if(ed > l) break;
        l -= ed; ans++;
    }
    if(ans == 1) cout<<ans<<" room, "<<l<<" square metre(s) left over"<<endl;
    else cout<<ans<<" rooms, "<<l<<" square metre(s) left over"<<endl;
}