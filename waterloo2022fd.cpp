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
const int MAX = 1e3 + 5;
int c, s, h = 0;
pii cl[MAX];
vi ans[MAX*10];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>c>>s;
    for(int i = 1; i <= c; i++){
        cin>>cl[i].s; cl[i].f = 0;
    }
    for(int i = 0; i < s; i++){
        for(int y = 0, a; y < 5; y++){
            cin>>a;
            if(cl[a].f < cl[a].s){
                ans[i].pb(a); h++; cl[a].f++;
            }
        }
    }
    cout<<h<<endl;
    for(int i = 0; i < s; i++){
        for(auto ed : ans[i]) cout<<ed<<" ";
        cout<<endl;
    }
}