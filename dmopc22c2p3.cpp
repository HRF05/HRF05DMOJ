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
const int MAX = 5e5 + 5;
int n, a[MAX], pre[MAX];
vector<int> chain[MAX], fact[MAX];
priority_queue<int> q;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++){
        int t = a[i];
        for(int y = 2; y <= sqrt(t); y++){
            if(!(t % y)){
                fact[y].pb(a[i]);
                while(!(t % y)) t /= y;
            }
        }
        if(t > 1) fact[t].pb(a[i]); 
    }
    for(int y = 2; y <= n/2; y++){
        for(int i = 1; i < fact[y].size(); i++){
            chain[fact[y][i-1]].pb(fact[y][i]);
            pre[fact[y][i]]++;
        }
    }
    for(int i = 1; i <= n; i++){
        if(!pre[a[i]]) q.push(a[i]);
    }
    for(int i = 0; i < n; i++){
        int t = q.top(); q.pop();
        cout<<t<<" ";
        for(auto ed : chain[t]){
            pre[ed]--;
            if(!pre[ed]) q.push(ed);
        }
    }
}