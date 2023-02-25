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
const int MAX = 1e3 + 5;
int sp[10][MAX][10][MAX], lg[MAX];
void init(vvi arr){
    static int n = arr[0].size();
    for(int i = 2; i <= n; i++) lg[i] = lg[i>>1]+1;
    static int btn = lg[n];
    for(int j = 0; j < n; j++){
        for(int i = 0; i < n; i++) sp[0][j][0][i] = arr[j][i];
        for(int y = 1; y <= btn; y++){
            for(int i = 0; i+(1<<y) <= n; i++) sp[0][j][y][i] = min(sp[0][j][y-1][i], sp[0][j][y-1][i+(1<<(y-1))]);
        }
    }
    for(int k = 1; k <= btn; k++){
        for(int j = 0; j < n; j++){
            for(int y = 0; y <= btn; y++){
                for(int i = 0; i < n; i++) sp[k][j][y][i] = min(sp[k-1][j][y][i], sp[k-1][j+(1<<(k-1))][y][i]);
            }
        }
    }
}
int query(int a, int b, int c, int d){
    int x = a, x1 = b, y = c, y1 = d;
    int lx = lg[x1-x+1], ly = lg[y1-y+1];
    return min(min(sp[lx][x][ly][y], sp[lx][x][ly][y1+1-(1<<ly)]), min(sp[lx][x1+1-(1<<lx)][ly][y], sp[lx][x1+1-(1<<lx)][ly][y1+1-(1<<ly)]));
}