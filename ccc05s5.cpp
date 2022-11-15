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
int n, bit[MAX], a[MAX];
double ans = 0;
set<int> cr;
void update(int x, int val){
    for(; x <= n; x += x&-x) bit[x] += val;
}
int get(int x){
    int ret = 0;
    for(; x > 0; x -= x&-x) ret += bit[x];
    return ret;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){ cin>>a[i]; cr.insert(a[i]); }
    vector<int> co(cr.begin(), cr.end());
    for(int i = 0; i < n; i++){
        int x = lower_bound(co.begin(), co.end(), a[i]) - co.begin() + 1;
        ans += i-get(x)+1;
        update(x, 1);
    }
    cout<<fixed<<setprecision(2)<<ans/n<<endl;
}