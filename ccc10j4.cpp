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
const int MAX = 2e1;
int n, a[MAX];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    while(1){
        cin>>n;
        if(!n) break;
        for(int i = 0; i < n; i++) cin>>a[i];
        for(int i = 0; i < n-1; i++) a[i] = a[i+1] - a[i];
        if(n == 1){
            cout<<0<<endl; continue;
        }
        for(int i = 1; i <= n; i++){
            bool rt = 0;
            for(int y = i, l = 0; y < n-1; y++, ++l %= i){
                if(a[y] != a[l]){
                    rt = 1; break;
                }
            }
            if(!rt){
                cout<<i<<endl;
                break;
            }
        }
    }
}