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
int T;
int rt[200011];
bool srt(tri a, tri b){
    return a.t > b.t;
}
int get(int i){
    if(rt[i] == i) return i;
    return rt[i] = get(rt[i]);
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>T;
    while(T--){
        int n;
        tri a[100011];
        cin>>n;
        set<int> keys;
        string ans = "YES";
        for(int i = 0; i < n; i++){
            cin>>a[i].f>>a[i].s>>a[i].t;
            keys.insert(a[i].f); keys.insert(a[i].s);
        }
        vi coord(keys.begin(), keys.end());
        for(int i = 0; i <= keys.size() + 1; i++){
            rt[i] = i;
        }
        for(int i = 0; i < n; i++){
            a[i].f = lower_bound(coord.begin(), coord.end(), a[i].f) - coord.begin();
            a[i].s = lower_bound(coord.begin(), coord.end(), a[i].s) - coord.begin();   
        }
        sort(a, a + n, srt);
        for(int i = 0; i < n; i++){
            if(a[i].t){
                int A = get(a[i].f);
                int B = get(a[i].s);
                if(A != B){
                    rt[A] = B;
                }
            }
            else{
                int A = get(a[i].f);
                int B = get(a[i].s);
                if(A == B){
                    ans = "NO";
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}