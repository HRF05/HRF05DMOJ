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
ll mulMod(ll a, ll t, ll n) {
	ll res = 0;
	a %= n;
	while(t > 0){
		if(t % 2) res = (res + a) % n;
		a = (a * 2) % n;
		t /= 2;
	}
	return res;
}
ll expMod(ll a, ll t, ll n){ 
	ll res = 1;
	while(t > 0){
		if(t % 2) res = mulMod(res, a, n);
		a = mulMod(a, a, n);
		t /= 2;
	}
	return res;
}
bool witness(ll a, ll n){
	ll u = n - 1, t = 0, xo, xt;
	while(!(u % 2)){
		u /= 2;
		t++;
	}
	xo = expMod(a, u, n); xt = xo;
	for(ll i = 0; i < t; i++){
		xt = mulMod(xo, xo, n);
		if(xt == 1 && xo != 1 && xo != n - 1) return true;
		xo = xt;
	}
	if(xt != 1) return true;
	return false;
}
bool millerRabin(ll n){
	ll a;
    a = (rand() % (n - 1)) + 1; // one test passes
	if(witness(a, n)) return false;
	return true;
}
ll n;
int main(){
    cin>>n;
    if(millerRabin(n-4)) cout<<2<<" "<<2<<" "<<n-4<<endl;
    else{
        for(ll i = 3; i < n; i++){
            if(millerRabin(i) && millerRabin(n - 3 - i)){
                cout<<3<<" "<<i<<" "<<n-i-3<<endl;
                return 0;
            }
        }
    }
}