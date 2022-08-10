#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_set>
#include <list>
#include <string>
#include <stack>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <random>
#include <map>
#include <unordered_map>
#include <complex>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;
typedef long long unsigned llu;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
struct tri {int first, second, t ;};
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
queue<pii> q;
vector<pii> adj[MAX];
int dist[MAX];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        dist[i] = INT_MAX;
    }
    for(int i = 0, a, b, c; i < m; i++){
        cin>>a>>b>>c;
        adj[a].pb(mp(b, c));
        adj[b].pb(mp(a, c));
    }
    q.push(mp(0, 1)); dist[1] = 0;
    while(!q.empty()){
        pii p = q.front(); q.pop();
        for(auto ed : adj[p.s]){
            if(dist[ed.f] > dist[p.s] + ed.s){
                dist[ed.f] = dist[p.s] + ed.s;
                q.push(mp(dist[ed.f], ed.f));
            }
        }
    }
    for(int i = 1; i <= n; i++){
        if(dist[i] != INT_MAX) cout<<dist[i]<<endl;
        else cout<<-1<<endl;
    }
}