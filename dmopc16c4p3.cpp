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
const int MAX = 1e5 + 5;
int n, s, q, d[MAX];
set<pii> ap[105];
char c;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>s;
    for(int i = 1; i <= n; i++) cin>>d[i];
    for(int i = 0, a, b; i < s; i++){
        cin>>a>>b;
        ap[b].insert({d[a], a});
    }
    
    cin>>q;
    while(q--){
        cin>>c;
        if(c == 'A'){
            int x, k; cin>>x>>k;
            ap[k].insert({d[x], x});
        }
        else if(c == 'S'){
            int x, k; cin>>x>>k;
            ap[k].erase({d[x], x});
        }
        else if(c == 'E'){
            int x, k; cin>>x>>k;
            for(int i = 0; i <= 100; i++) ap[i].erase({d[x], x});
            d[x] = k;
        }
        else{
            int k; cin>>k;
            cout<<(ap[k].empty()? -1 : ap[k].begin()->s)<<endl;
        }
    }
}