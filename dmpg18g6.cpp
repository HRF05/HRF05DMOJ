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
const int MAX = 1e5 + 5;
ll n, c, k, s[MAX], dist[MAX], a;
bool inq[MAX] { 0 };
vector<ll> cl[MAX];
vector<ll> st[MAX];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>c>>k;
    for(int i = 1; i <= n; i++){
        cin>>s[i];
        dist[i] = LLONG_MAX;
    }
    for(int i = 1, t; i <= n; i++){
        cin>>t;
        while(t--){
            cin>>a;
            cl[a].pb(i);
            st[i].pb(a);
        }
    }
    queue<int> q;
    q.push(1); dist[1] = 0;
    while(!q.empty()){
        int u = q.front(); q.pop();
        inq[u] = 0;
        for(int cs : st[u]){
            for(int ot : cl[cs]){
                if(ot == u) continue;
                if(dist[u] + abs(s[u] - s[ot]) + k < dist[ot]){
                    dist[ot] = dist[u] + abs(s[u] - s[ot]) + k;
                    if(!inq[ot]){
                        q.push(ot);
                        inq[ot] = 1;
                    }
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(dist[i] == LLONG_MAX) cout<<-1<<endl;
        else cout<<dist[i]<<endl;
    }
}