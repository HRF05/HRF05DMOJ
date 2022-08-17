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
#include <cstring>
using namespace std;
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
const int MX = 5e5 + 5;
int n, q, a[MX];
pii ml[MX], mr[MX]; // ml=right mr=left
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
        mr[i].s = 1;
        if(a[i] == mr[i-1].f) mr[i].s += mr[i-1].s; 
        else if(a[i] <= mr[i-1].f) mr[i].s = mr[i-1].s;
        mr[i].f = max(mr[i-1].f, a[i]);
    }
    for(int i = n; i > 0; i--){
        ml[i].s = 1;
        if(a[i] == ml[i+1].f) ml[i].s += ml[i+1].s; 
        else if(a[i] <= ml[i+1].f) ml[i].s = ml[i+1].s;
        ml[i].f = max(ml[i+1].f, a[i]);
    }
    for(int i = 0, ta, tb; i < q; i++){
        cin>>ta>>tb;
        ta--; tb++;
        if(mr[ta].f > ml[tb].f){
            cout<<mr[ta].f<<" "<<mr[ta].s<<endl;
        }
        else if(mr[ta].f < ml[tb].f){
            cout<<ml[tb].f<<" "<<ml[tb].s<<endl;
        }
        else{
            cout<<mr[ta].f<<" "<<mr[ta].s + ml[tb].s<<endl;
        }
    }
}