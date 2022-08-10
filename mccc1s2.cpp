#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_set>
#include <list>
#include <string>
#include <stack>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <random>
#include <map>
#include <unordered_map>
#include <complex>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;
typedef long long unsigned llu;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
struct tri {int first, second, t ;};
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
const int MAX = 2001;
int n, g[MAX][MAX], ind = 0;
pair<bool, int> ans[4001];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i =0 ; i < n; i++){
        for(int y= 0 ; y < n; y++){
            cin>>g[i][y];
        }
    }
    for(int i = 0; i < n; i++){
        if(g[0][i] == 1){
            ans[ind++] = mp(false, i + 1);
            for(int y = 0; y < n; y++){
                g[y][i] = 1 - g[y][i];
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(g[i][0] == 1){
            ans[ind++] = mp(true, i + 1);
            for(int y = 0; y < n; y++){
                g[i][y] = 1 - g[i][y];
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int y = 0; y < n; y++){
            if(g[i][y] == 1){
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    cout<<ind<<endl;
    for(int i = 0; i < ind; i++){
        if(ans[i].f) cout<<"R ";
        else cout<<"C ";
        cout<<ans[i].s<<endl;
    }
}