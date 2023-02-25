#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long long unsigned llu;
#define int ll
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
const int MAX = 2e5 + 5;
int n, a[MAX], lo = 0;
bool check(int h){
    int tw = 0;
    for(int i = 0; i < n; i++){
        if(2*tw+a[i] > h){
            if((h-a[i])%2) tw -= (h-a[i])/2, tw++;
            else tw -= (h-a[i])/2;
        }
        else tw = h-(a[i]+tw*2);
        assert(tw >= 0);
    }
    return tw==0;
}
signed main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>a[i]; lo = max(lo, a[i]);
    }
    for(int i = lo; i < 1e6+5; i++){
        if(check(i)){
            cout<<i<<endl; return 0;
        }
    }
    cout<<-1<<endl;
}