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
int tot[10];
vi adj[10], ans;
bool srt(int a, int b){return a < b; }
priority_queue<int, vi, greater<int>> q;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    adj[1].pb(7); tot[7]++;
    adj[1].pb(4); tot[4]++;
    adj[2].pb(1); tot[1]++;
    adj[3].pb(4); tot[4]++;
    adj[3].pb(5); tot[5]++;
    while(1){
        int a, b; cin>>a>>b;
        if(a == 0) break;
        adj[a].pb(b); tot[b]++;
    }
    for(int i = 1; i < 8; i++){
        if(!tot[i]) q.push(i);
    }
    while(!q.empty()){
        int u = q.top(); q.pop();
        ans.pb(u);
        for(auto ed : adj[u]){
            if(!--tot[ed]) q.push(ed);
        }
    }
    if(ans.size() < 7){
        cout<<"Cannot complete these tasks. Going to bed."<<endl;
        return 0;
    }
    for(auto ed : ans) cout<<ed<<" ";
    cout<<endl;
}