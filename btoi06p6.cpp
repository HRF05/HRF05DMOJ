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
const int MAX = 1e2 + 5;
int n, ar[MAX][MAX]; string dp[MAX][MAX];
string add(string sl, string ss){
    string a;
    if(ss.length()>sl.length()) swap(ss, sl);
    int c = 0, y = sl.length() - ss.length();
    for (int i = ss.length() - 1; i >= 0; i--){
        int t = (ss[i] - 48) + (sl[i + y] - 48) + c;
        a.push_back(t % 10 + 48);
        c = t / 10;
    }
    for (int i = y - 1; i >= 0; i--){
        int t = (sl[i] - 48) + c;
        a.push_back(t % 10 + 48);
        c = t / 10;
    }
    if (c > 0) a.push_back(c + 48);
    reverse(a.begin(), a.end());
    return a;
}
string get(int u, int v){
    if(u == 1 && v == 1) return "1";
    if(dp[u][v] != "-1") return dp[u][v];
    string ret = "0";
    for(int i = 1; u-i > 0; i++){
        if(ar[u-i][v] == i) ret = add(get(u-i, v), ret);
    }
    for(int i = 1; v-i > 0; i++){
        if(ar[u][v-i] == i) ret = add(get(u, v-i), ret);
    }
    return dp[u][v] = ret;
}
signed main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int y = 1; y <= n; y++){ cin>>ar[i][y]; dp[i][y] = "-1";}
    }
    cout<<get(n, n)<<endl;
}