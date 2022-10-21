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
const int MAX = 1e6 + 5;
int t, n, a[MAX], h;
bool ans;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n; ans = 0; h = -1;
        for(int i = 0; i < n; i++){
            cin>>a[i];
            if(i && a[i] && a[i-1]){
                if(a[i] > a[i-1]) h = i % 2;
                else if(a[i] < a[i-1]) h = 1 - (i % 2);
                else if(a[i] == a[i-1]) ans = 1;
            }
        }
        if(h == -1 || ans){
            if(ans) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
            continue;
        }
        for(int i = 1; i < n; i++){
            if(a[i] && a[i-1]){
                if((i % 2) == h){
                    if(a[i] <= a[i-1]) ans = 1;
                }
                else{
                    if(a[i] >= a[i-1]) ans = 1;
                }
            }
        }
        if(ans) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}