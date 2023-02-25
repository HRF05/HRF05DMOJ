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
const int MAX = 1e6 + 5;
int n, a[MAX], psa[MAX*3], ans;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i];
        for(int y = 0; i+y*n < 3*MAX; y++) psa[i+y*n] = a[i];
    }
    for(int i = 1; i < 3*MAX; i++) psa[i] += psa[i-1];
    for(int i = 0; i < n; i++){
        int y = i+2*n*(MAX/n), l = 0, r = 0;
        l = psa[y-1] - psa[y-a[i]-1], r = psa[i+a[i]] - psa[i];
        ans = max(ans, abs(l-r)+a[i]);
    }
    cout<<ans<<endl;
}