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
int n, q, dif[MAX], ar[MAX], z = 0;
string a, b;
map<char, int> mo;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>a>>b>>q; mo['R'] = 0; mo['G'] = 1; mo['B'] = 2;
    for(int i = 1; i <= n; i++){
        ar[i] = (mo[a[i-1]] - mo[b[i-1]] + 3) % 3;
    }
    dif[1] = ar[1]; z = ar[1] == 0;
    for(int i = 2; i <= n; i++){
        dif[i] = ar[i]-ar[i-1];
        z += dif[i] == 0;
    }
    if(z == n){
        cout<<0<<endl; return 0;
    }
    for(int i = 1; i <= q; i++){
        int l, r; cin>>l>>r; r++;
        if(!dif[l]) z--;
        if(!dif[r] && r <= n) z--;
        dif[l]++; dif[r]--; dif[l] = (dif[l] + 3) % 3; dif[r] = (dif[r] + 3) % 3;
        if(!dif[l]) z++;
        if(!dif[r] && r <= n) z++;
        if(z == n){
            cout<<i<<endl; return 0;
        }
    }
    cout<<-1<<endl;
}