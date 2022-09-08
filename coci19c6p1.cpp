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
set<int> date;
string dt;
int q;
int md[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool palin(int i){
	int day = (i % 10) * 10 + (i % 100) / 10, month = i / 1000 + ((i / 100) % 10) * 10;
	return (day && month && day <= md[month - 1] && month <= 12);
}
string inttodt(int i){
	string t;
	t += i % 10 + '0';
	t += (i / 10) % 10 + '0';
	t += ".";
	t += (i / 100) % 10 + '0';
	t += i / 1000 + '0';
	t += ".";
	t += (i / 1000) + '0';
	t += (i / 100) % 10 + '0';
	t += (i / 10) % 10 + '0';
	t += i % 10 + '0';
    t += ".";
	return t;
}
bool srt(string a, string b){
    int mna = (a[3] - '0') * 10 + a[4] - '0', mnb = (b[3] - '0') * 10 + b[4] - '0', dta = (a[0] - '0') * 10 + a[1] - '0', dtb = (b[0] - '0') * 10 + b[1] - '0';
    if(mna == mnb){
        return dta > dtb;
    }
    return mna > mnb;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    for(int i = 1; i < 10000; i++){
        if(palin(i)) date.insert(i);
    }
    cin>>q;
    while(q--){
        cin>>dt;
        int year = (dt[6] - '0') * 1000 + (dt[7] - '0') * 100 + (dt[8] - '0') * 10 + (dt[9] - '0');
        if(date.find(year) != date.end()){
            string dtb = inttodt(year);
            if(srt(dtb, dt)){
                cout<<dtb<<endl;
            }
            else{
                cout<<inttodt(*(date.lower_bound(year + 1)))<<endl;
            }
        }
        else{
            cout<<inttodt(*(date.lower_bound(year)))<<endl;
        }
    }
}