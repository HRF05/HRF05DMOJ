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
string s;
string inc(string a){
    if(a == "23:59") a = "00:00";
    else{
        if(a[4] == '9'){
            if(a[3] == '5'){
                if(a[1] == '9'){
                    a[0]++;
                    a[1] = a[3] = a[4] = '0';
                }
                else{
                    a[1]++;
                    a[3] = a[4] = '0';
                }
            }
            else{
                a[3]++;
                a[4] = '0';
            }
        }
        else{
            a[4]++;
        }
    }
    return a;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>s;
    for(int i = 0; i < 120; i++){
        if((s[0] == '0' && s[1] >= '7' && s[1] <= '9') || (s[0] == '1' && s[1] >= '5' && s[1] <= '8')) s = inc(inc(s));
        else s = inc(s);
    }
    cout<<s<<endl;
}