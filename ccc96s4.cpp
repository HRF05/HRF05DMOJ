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
int toN(string s){
    int ret = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'I') ret++;
        if(s[i] == 'V'){
            if(i && s[i-1] == 'I') ret -= 2;
            ret += 5;
        }
        if(s[i] == 'X'){
            if(i && s[i-1] == 'I') ret -= 2;
            ret += 10;
        }
        if(s[i] == 'L'){
            if(i && s[i-1] == 'X') ret -= 20;
            ret += 50;
        }
        if(s[i] == 'C'){
            if(i && s[i-1] == 'X') ret -= 20;
            ret += 100;
        }
        if(s[i] == 'D'){
            if(i && s[i-1] == 'C') ret -= 200;
            ret += 500;
        }
        if(s[i] == 'M'){
            if(i && s[i-1] == 'C') ret -= 200;
            ret += 1000;
        }
    }
    return ret;
}
vector<pair<int, string>> ma;
void init(){
    ma.pb({1000, "M"});
    ma.pb({900, "CM"});
    ma.pb({500, "D"});
    ma.pb({400, "CD"});
    ma.pb({100, "C"});
    ma.pb({90, "XC"});
    ma.pb({50, "L"});
    ma.pb({40, "XL"});
    ma.pb({10, "X"});
    ma.pb({9, "IX"});
    ma.pb({5, "V"});
    ma.pb({4, "IV"});
    ma.pb({1, "I"});
}
string toR(int n){
    string ret = "";
    for(auto ed : ma){
        while(n >= ed.f){
            ret += ed.s;
            n -= ed.f;
        }
    }
    return ret;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int q; cin>>q;
    init();
    while(q--){
        string t, a, b; cin>>t; cout<<t;
        int st = 0;
        for(int i = 0; i < t.length(); i++){
            if(t[i] == '+'){
                st = i;
                a = t.substr(0, i);
            }
            if(t[i] == '='){
                b = t.substr(st+1, i-st-1);
            }
        }
        int res = toN(a) + toN(b);
        cout<<(res>1000? "CONCORDIA CUM VERITATE" : toR(res))<<endl;
    }
}