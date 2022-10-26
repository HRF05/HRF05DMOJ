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
int t, n;
ll a[3][MAX];
bool lexg(int f, int s){
    for(int i = 0; i < n; i++){
        if(a[f][i] > a[s][i]) return 1;
        else if(a[f][i] < a[s][i]) return 0;
    }
    return 1;
}
bool lexgr(int f, int s){
    for(int i = n-1; i >= 0; i--){
        if(a[f][i] > a[s][i]) return 1;
        else if(a[f][i] < a[s][i]) return 0;
    }
    return 1;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 0; i < 3; i++){
            for(int y = 0; y < n; y++) cin>>a[i][y];
        }
        bool o = lexg(0, 1);
        if(o && lexg(0, 2)){ // 0
            if(lexgr(1, 2)) cout<<"Josh Nils Mike"<<endl;
            else cout<<"Josh Mike Nils"<<endl;
        }
        else if(!o && lexg(1, 2)){ // 1
            if(lexgr(0, 2)) cout<<"Nils Josh Mike"<<endl;
            else cout<<"Mike Josh Nils"<<endl;
        }
        else{ // 2
            if(lexgr(0, 1)) cout<<"Nils Mike Josh"<<endl;
            else cout<<"Mike Nils Josh"<<endl;
        }
    }
}