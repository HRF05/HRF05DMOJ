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
struct tri {int first, second, t;bool operator<(const tri& T){return t < T.t;}};
#define f first
#define s second
#define pb push_back
#define pf push_front
#define mp make_pair
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _; bool _sign;
const int MAX = 1e5 + 5;
int n, m, ds[MAX], ans = 0;
vector<tri> edg;
int find(int x){
  return ds[x] == x? x : ds[x]=find(ds[x]);
}
bool merge(int a, int b){
  int x = find(a), y = find(b);
  if(x != y) return ds[x] = y;
  return 0;
}
int main(){
  cin.sync_with_stdio(0); cin.tie(0);
  cin>>n>>m;
  for(int i = 1; i <= n; i++) ds[i] = i;
  for(int i = 0, cur, pre; i < n; i++, pre = cur){
    cin>>cur;
    if(i) edg.pb({i, i+1, cur-pre});
  }
  int e = 0;
  for(int i = 0, a, b; i < m; i++){
    cin>>a>>b;
    if(merge(a, b)) e++;
  }
  sort(edg.begin(), edg.end()); 
  for(auto ed : edg){
    if(e == n-1) break;
    if(merge(ed.f, ed.s)){
      e++;
      ans += ed.t;
    }
  }
  cout<<ans<<endl;
}
