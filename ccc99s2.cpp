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
struct tri {int first, second, t;bool operator<(const tri& T){return second > T.second;}};
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
int q; string b;
map<string, bool> mo;
bool vay(int pos){
    return (b[pos] >= '0' && b[pos] <= '9' && b[pos+1] >= '0' && b[pos+1] <= '9');
}
bool vam(int pos){
    if(b[pos] == '0') return (b[pos+1]>='1' && b[pos+1] <= '9');
    if(b[pos] == '1') return (b[pos+1]>='0' && b[pos+1] <= '2');
    return 0;
}
bool vad(int pos){
    if(b[pos] == '0') return (b[pos+1]>='1' && b[pos+1] <= '9');
    if(b[pos] == '1' || b[pos] == '2') return (b[pos+1]>='0' && b[pos+1] <= '9');
    if(b[pos] == '3') return (b[pos+1]>='0' && b[pos+1] <= '1');
    return 0;
}
int valid(int pos){
    if(pos > 7  && b[pos-3] == '/' && b[pos-6] == '/'){
        if(pos > 8 && b[pos-9] != ' ') return -1;
        if(!vam(pos-5) || !vad(pos-8) || !vay(pos-2)) return -1;
        return pos-2;
        
    }
    if(pos > 7 && b[pos-4] == ',' && b[pos-3] == ' ' && b[pos-7] == ' '){
        bool va = 0;
        for(int i = 8; pos-i >= 0; i++){
            if(b[pos-i] == ' ') break;
            if(mo[b.substr(pos-i, i-7)] && (pos-i==0 || b[pos-i-1] == ' ')) va = 1;
        }
        if(!va || !vad(pos-6) || !vay(pos-2)) return -1;
        return pos-2;
    }
    if(pos > 7  && b[pos-3] == '.' && b[pos-6] == '.'){
        if(pos > 8 && b[pos-9] != ' ') return -1;
        if(!vam(pos-5) || !vad(pos-2) || !vay(pos-8)) return -1;
        return pos-8;
    }
    return -1;
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>q; getline(cin, b);
    mo["February"] = 1; mo["January"] = 1; mo["March"] = 1; mo["April"] = 1; mo["May"] = 1; mo["June"] = 1; mo["July"] = 1; mo["August"] = 1; mo["September"] = 1; mo["October"] = 1; mo["November"] = 1; mo["December"] = 1;
    while(q--){
        getline(cin, b);
        set<int> yr;
        for(int i = 0; i < b.length(); i++){
            int v = valid(i);
            if(v == -1 || (b[i] != ',' && b[i] != ' ')) continue;
            yr.insert(v);
        }
        int v = valid(b.length());
        if(v != -1) yr.insert(v);
        for(int i = 0; i < b.length(); i++){
            if(yr.count(i)){
                int t = (b[i]-'0')*10+b[i+1]-'0';
                if(t <= 24) cout<<"20";
                else cout<<"19";
            }
            cout<<b[i];
        }
        cout<<endl;
    }
}