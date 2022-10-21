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
const int MAX = 5e5;
int n, h, u[MAX], d[MAX], mi = INT_MAX, nm;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>h;
    for(int i = 0, a; i < n; i++){
        cin>>a;
        if(i % 2) d[a]++;
        else u[a]++;
    }
    for(int i = h-2; i+1; i--){
        u[i] += u[i+1];
        d[i] += d[i+1];
    }
    for(int i = h-1; i+1; i--){
        if(u[i] + d[h-i+1] < mi){
            mi = u[i] + d[h-i+1];
            nm = 1;
        }
        else if(u[i] + d[h-i+1] == mi) nm++;
    }
    cout<<mi<<" "<<nm<<endl;
}