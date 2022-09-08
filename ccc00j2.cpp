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
int l, r, ans;
bool isSm(string s){
    string rs;
    for(int i = s.length() - 1; i >= 0; i--){
        if(s[i] == '1' || s[i] == '0' || s[i] == '8'){
            rs += s[i];
        }
        else if(s[i] == '6'){
            rs += "9";
        }
        else if(s[i] == '9'){
            rs += '6';
        }
        else{
            return 0;
        }
    }
    if(rs == s) return 1;
    return 0;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>l>>r;
    for(int i = l; i <= r; i++){
        if(isSm(to_string(i))) ans++;
    }
    cout<<ans<<endl;
}