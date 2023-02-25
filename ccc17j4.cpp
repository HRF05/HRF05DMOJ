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
string tim = "1200";
int ans = 0, d;
void cloc(){
    if(tim[3] == '9' && tim[2] == '5'){
        if(tim[0] == '1' && tim[1] == '2'){
            tim = "0100";
        }
        else if(tim[1] == '9'){
            tim = "1000";
        }
        else{
            tim[1]++; tim[2] = '0'; tim[3] = '0';
        }
    }
    else if(tim[3] == '9'){
        tim[2]++; tim[3] = '0';
    }
    else tim[3]++;
    if(tim[0] == '0'){
        if(tim[1]-tim[2] == tim[2]-tim[3]) ans++;
    }
    else{
        if(tim[0]-tim[1] == tim[1]-tim[2] && tim[1]-tim[2] == tim[2]-tim[3]) ans++;
    }
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>d;
    while(d >= 720){
        d -= 720;
        ans += 31;
    }
    while(d--) cloc();
    cout<<ans<<endl;
}