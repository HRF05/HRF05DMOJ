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
int n;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    set<string> dict;
    dict.insert("a");
    dict.insert("ka");
    dict.insert("na");
    dict.insert("ha");
    dict.insert("ma");
    dict.insert("ra");
    dict.insert("i");
    dict.insert("ki");
    dict.insert("ni");
    dict.insert("hi");
    dict.insert("mi");
    dict.insert("ri");
    dict.insert("u");
    dict.insert("ku");
    dict.insert("nu");
    dict.insert("fu");
    dict.insert("mu");
    dict.insert("ru");
    dict.insert("e");
    dict.insert("ke");
    dict.insert("ne");
    dict.insert("he");
    dict.insert("me");
    dict.insert("re");
    dict.insert("o");
    dict.insert("ko");
    dict.insert("no");
    dict.insert("ho");
    dict.insert("mo");
    dict.insert("ro");
    cin>>n;
    for(int z = 0; z < n; z++){
        string s;
        cin>>s;
        bool B = true;
        for(int i = 0; i < s.length(); i++){
            bool b = false;
            if(dict.count(s.substr(i, 1))) b = true;
            if(i && dict.count(s.substr(i-1, 2))) b = true;
            if(i < s.length() - 1 && dict.count(s.substr(i, 2))) b = true;
            if(!b){
                B = false;
                break;
            }
        }
        if(B) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}