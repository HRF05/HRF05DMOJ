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
vector<char> a[4];
int in = -1, tot = 0;
string s;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>s;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'C' || s[i] == 'D' || s[i] == 'H' || s[i] == 'S') in++;
        else a[in].pb(s[i]);
    }
    cout<<"Cards Dealt              Points"<<endl;
    for(int i = 0, p; i < 4; i++){
        if(!i) cout<<"Clubs";
        else if(i == 1) cout<<"Diamonds";
        else if(i == 2) cout<<"Hearts";
        else cout<<"Spades";
        if(!a[i].size()) p = 3;
        else if(a[i].size() == 1) p = 2;
        else if(a[i].size() == 2) p = 1;
        else p = 0;
        for(int y = 0; y < a[i].size(); y++){
            cout<<' '<<a[i][y];
            if(a[i][y] == 'A') p += 4;
            else if(a[i][y] == 'K') p += 3;
            else if(a[i][y] == 'Q') p += 2;
            else if(a[i][y] == 'J') p++;
        }
        cout<<"             "<<p<<endl;
        tot += p;
    }
    cout<<"                       Total "<<tot<<endl;
}