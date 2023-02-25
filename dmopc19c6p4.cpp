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
const int MAX = 5e5 + 5;
int n, q, ar[MAX];
bool vis[MAX];
gp_hash_table<int, int> bit[MAX];
void update(int x, int val, int de){
  for(; x <= n; x+=x&-x) bit[x][val] += de;
}
int query(int x, int val){
  int ret = 0;
  for(; x; x-=x&-x) ret += bit[x][val];
  return ret;
}
int main(){
  cin.sync_with_stdio(0); cin.tie(0);
  cin>>n>>q;
  for(int i = 1; i <= n; i++) update(i, 0, 1);
  while(q--){
    int t;
    cin>>t;
    if(t == 1){
      int i; cin>>i; 
      update(i, ar[i], -1);
      ar[i]++; update(i, ar[i], 1);
    }
    else if(t == 2){
      int i; cin>>i;
      update(i, ar[i], -1);
      ar[i]--; update(i, ar[i], 1);
    }
    else{
      int l, r, c; cin>>l>>r>>c;
      cout<<query(r, c) - query(l-1, c)<<endl;
    }
  }
}