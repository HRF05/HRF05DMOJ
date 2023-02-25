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
const int MAX = 1e5 + 5;
int n, fr[MAX], m1, m2, x1, x2, i1 = INT_MAX, i2 = INT_MAX;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 0, a; i < n; i++){
        cin>>a; fr[a]++;
    }
    for(int i = 1; i <= 1000; i++){
        if(fr[i] >= m1) m2 = m1, m1 = fr[i];
        else if(fr[i] > m2) m2 = fr[i];
    }
    for(int i = 1; i <= 1000; i++){
        if(fr[i] == m1) i1 = min(i1, i), x1 = max(x1, i);
        if(fr[i] == m2) i2 = min(i2, i), x2 = max(x2, i);
    }
    if(i2 == INT_MAX) i2 = x1;
    cout<<max(abs(x2-i1), abs(x1-i2))<<endl;
}