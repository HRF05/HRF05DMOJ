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
const int MAX = 101;
int n;
pii ar[MAX];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 0; i <= 100; i++) ar[i].f = ar[i].s = 0;
    for(int i = 0, t = 0, a; i < n; i++, t++){
        char c; cin>>c>>a;
        if(c == 'W') t += a-2;
        else if(c == 'R') ar[a].s = t;
        else{
            ar[a].f += t-ar[a].s;
            ar[a].s = 0;
        }
    }
    for(int i = 0; i <= 100; i++){
        if(ar[i].s) cout<<i<<" "<<-1<<endl;
        else if(ar[i].f) cout<<i<<" "<<ar[i].f<<endl;
    }
}