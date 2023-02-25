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
int pos = 1;
map<int, int> ma;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    for(int i = 1; i <= 100; i++) ma[i] = i;
    ma[9] = 34; ma[40] = 64; ma[67] = 86; ma[54] = 19; ma[90] = 48; ma[99] = 77;
    while(1){
        int r; cin>>r;
        if(!r) break;
        if(pos + r <= 100) pos = ma[pos+r];
        cout<<"You are now on square "<<pos<<endl;
        if(pos == 100){cout<<"You Win!"<<endl; return 0;}
    }
    cout<<"You Quit!"<<endl;
}