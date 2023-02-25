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
class Base{
public:
    Base();
    void setNum(ll number, int curBase);
    void convert(int newBase);
    ll num;
private:
    ll toBTen();
    int base;
};
Base::Base(){
    num = 0; base = 10;
}
ll Base::toBTen(){
    int cur = 0, lng = 1; ll ret = 0;
    while(lng <= num){
        int t = (num/lng)%10;
        ret += t * pow(base, cur);
        cur++; lng *= 10;
    }
    return ret;
}
void Base::convert(int newBase){
    if(base != 10) num = toBTen();
    int up = log(num)/log(newBase); ll ret = 0;
    for(int i = up, k = pow(newBase, up); i >= 0; i--, k /= newBase){
        while(num-k >= 0){
            num -= k; ret += pow(10, i);
        }
    }
    base = newBase; num = ret;
}
void Base::setNum(ll number, int curBase){
    num = number; base = curBase;
}
int main(){
    int e, n, a[10];
    cin>>e>>n;
    Base cur;
    for(int i = 0; i < n; i++) cin>>a[i];
        cur.setNum(a[n-1], 10);
        for(int i = n-2; i >= 0; i--){
            cur.setNum(a[i], cur.num);
            cur.convert(10);
        }
    cur.setNum(e, cur.num); cur.convert(10);
    cout<<cur.num<<endl;
}