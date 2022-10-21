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
const int MAX = 1e5+5;
int n, k, t, b[MAX], mi, nmi, ans[MAX];
bool dl[MAX];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>k>>t;
    while(t--){
        nmi = INT_MAX;
        for(int i = 0; i < n; i++){
            cin>>b[i];
            nmi = min(nmi, b[i]);
            dl[i] = 0;
        }
        for(int i = 0, c = 0; i < k; i++){
            mi = nmi; nmi = INT_MAX; c = 0;
            for(int y = n-1; y >= 0; y--){
                if(dl[y]) continue;
                if(b[y] == mi){
                    dl[y] = 1;
                    c++;
                }
                else{
                    b[y] += c;
                    nmi = min(nmi, b[y]);
                }
            }
        }    
        if(nmi != INT_MAX && i != k-1) ans[i] = nmi - mi;
        else{
            ans[i] = n - mi;
            for(int y = i+1; y < k; y++) ans[y] = 0;
            break;
        }
    }
    for(int i = 0; i < k; i++) cout<<ans[i]<<" ";
    cout<<endl;
}