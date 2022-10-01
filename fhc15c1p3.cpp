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
const int MAX = 2e3 + 5, mod = 1e9 + 7;
int Q, a, b, n = 0, F[MAX][MAX], G[MAX][MAX];
char B;
int f(int u, int t, int U, int T){
    if((u == U && t == T) || (t == T && u > T) || (u == U)) return 1;
    if(t == T || (u > 0 && u <= t)) return 0;
    if(F[u][t] != -1) return F[u][t];
    return F[u][t] = (f(u + 1, t, U, T) + f(u, t + 1, U, T)) % mod;
}
int g(int u, int t, int U, int T){
    if(t == T) return 1;
    if(u == U || u > t) return 0;
    if(G[u][t] != -1) return G[u][t];
    return G[u][t] = (g(u + 1, t, U, T) + g(u, t + 1, U, T)) % mod;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>Q;
    while(n < Q){
        cin>>a>>B>>b;
        for(int i = 0; i < a; i++){
            for(int y = 0; y < b; y++){
                F[i][y] = -1;
                G[i][y] = -1;
            }
        }
        cout<<"Case #"<<++n<<": "<<f(1, 0, a, b)<<" "<<g(0, 0, a, b)<<endl;
    }
}