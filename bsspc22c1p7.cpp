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
struct tri {int first, second;bool operator<(const tri& T){return first < T.first;}};
#define f first
#define s second
#define pb push_back
#define pf push_front
#define mp make_pair
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
const int MAX = 1e6 + 5;
int n, m, ans = INT_MIN, m1 = INT_MIN;
pii a[MAX];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        cin>>a[i].f>>a[i].s;
        m1 = max(m1, a[i].f - a[i].s);
    }
    if(m == 1){cout<<m1<<endl; return 0;}
    sort(a, a+n, greater<pii>());
    priority_queue<int> q;
    for(int i = 0; i < n; i++){
        if(i >= m-1){
            ans = max(ans, a[i].f - max(q.top(), a[i].s));
            if(a[i].s < q.top()){
                q.pop(); q.push(a[i].s);
            }
        }
        else q.push(a[i].s);
    }
    cout<<ans<<endl;
}