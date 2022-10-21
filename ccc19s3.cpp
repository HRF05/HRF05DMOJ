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
int g[3][3], r[3], c[3], pos[6][2]{{1, 1}, {0, 1}, {2, 1}, {1, 0}, {1, 2}, {0, 0}}, n = 0; string s;
bool x[3][3];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    for(int i = 0; i < 3; i++){
        for(int y = 0; y < 3; y++){
            cin>>s;
            if(s == "X"){
                x[i][y] = 1;
                r[i]++;c[y]++;
                n++;
            }
            else g[i][y] = stoi(s);
        }
    }
    while(n){
        bool f = 0;
        for(int i = 0; i < 3 && !f; i++){
            if(r[i] == 1){
                if(x[i][0]){ g[i][0] = 2*g[i][1] - g[i][2]; r[i]--; c[0]--; n--; x[i][0] = 0; }
                if(x[i][1]){ g[i][1] = (g[i][0] + g[i][2]) / 2; r[i]--; c[1]--; n--; x[i][1] = 0; }
                if(x[i][2]){ g[i][2] = 2*g[i][1] - g[i][0]; r[i]--; c[2]--; n--; x[i][2] = 0; }
                f = 1;
            }
        }
        for(int i = 0; i < 3 && !f; i++){
            if(c[i] == 1){
                if(x[0][i]){ g[0][i] = 2*g[1][i] - g[2][i]; r[0]--; c[i]--; n--; x[0][i] = 0; }
                if(x[1][i]){ g[1][i] = (g[0][i] + g[2][i]) / 2; r[1]--; c[i]--; n--; x[1][i] = 0; }
                if(x[2][i]){ g[2][i] = 2*g[1][i] - g[0][i]; r[2]--; c[i]--; n--; x[2][i] = 0; }
                f = 1;
            }
        }
        for(int i = 0; i < 6 && !f; i++){
            int t = pos[i][0], e = pos[i][1];
            if(x[t][e]){ g[t][e] = 0; x[t][e] = 0; r[t]--; c[e]--; n--; f = 1;}
        }
    }
    for(int i = 0; i < 3; i++){
        for(int y = 0; y < 3; y++) cout<<g[i][y]<<" ";
        cout<<endl;
    }
}