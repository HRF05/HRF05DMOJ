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
const int MAX = 1e6 + 5;
string a, b;
bool ans;
int cur, t;
bool get(int q){
    stack<int> s;
    while(cur < a.length()){
        if(a[cur] == b[q] && s.empty()) return 1;
        s.push(cur++);
        while(!s.empty() && a[cur] == a[s.top()]){
            if(a[cur] == 'z') return 0;
            a[cur]++; s.pop();
        }
    }
    return 0;
}
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>t;
    while(t--){
        cin>>a>>b; cur = 0; ans = 0;
        for(int i = 0; i < b.length(); i++){
            if(!get(i)){
                ans = 1; break;
            }
            cur++;
        }
        if(cur != a.length()) ans = 1;
        cout<<(ans? "NO" : "YES")<<endl;
    }
}