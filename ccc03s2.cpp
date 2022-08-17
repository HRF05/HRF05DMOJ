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
int t;
map<char, bool> vwl;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>t;
    vwl['a'] = true;vwl['e'] = true;vwl['i'] = true;vwl['o'] = true;vwl['u'] = true;
    string q;
    getline(cin, q);
    while(t--){
        string a[4];
        getline(cin, a[0]);getline(cin, a[1]);getline(cin, a[2]);getline(cin, a[3]);
        for(int i = 0; i < 4; i++){
            q = "";
            for(int y = 0; y < a[i].length(); y++){
                a[i][y] = tolower(a[i][y]);
            }
            while(!a[i].empty() && !vwl[a[i].back()] && a[i].back() != ' '){
                q += a[i].back(); a[i].pop_back();
            }
            if(vwl[a[i].back()]) q += a[i].back();
            a[i] = q;
        }
        if(a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) cout<<"perfect"<<endl;
        else if(a[0] == a[1] && a[2] == a[3]) cout<<"even"<<endl;
        else if(a[0] == a[2] && a[1] == a[3]) cout<<"cross"<<endl;
        else if(a[0] == a[3] && a[1] == a[2]) cout<<"shell"<<endl;
        else cout<<"free"<<endl;
    }
}