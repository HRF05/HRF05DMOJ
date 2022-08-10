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
    cin>>n;
    for(int i = 0; i < n; i++){
        int c1[26] { 0 }, c2[26] { 0 };
        int cnst = 1, ind;
        string s;
        cin>>s;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '+'){
                cnst = 1;
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                if(s[i + 1] >= '1' && s[i + 1] <= '9'){
                    c1[s[i] - 'A'] += cnst * (s[i + 1] - '0');
                }
                else{
                    c1[s[i] - 'A'] += cnst;
                }
            }
            else if(s[i] >= '1' && s[i] <= '9' && (!i || (s[i-1] == '+' || s[i-1] == '>'))){
                cnst *= s[i] - '0';
            }
            else if(s[i] == '-' && s[i + 1] == '>'){
                cnst = 1;
                ind = i + 2;
                break;
            }
        }
        for(int i = ind; i < s.length(); i++){
            if(s[i] == '+'){
                cnst = 1;
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                if(s[i + 1] >= '1' && s[i + 1] <= '9'){
                    c2[s[i] - 'A'] += cnst * (s[i + 1] - '0');
                }
                else{
                    c2[s[i] - 'A'] += cnst;
                }
            }
            else if(s[i] >= '1' && s[i] <= '9' && (!i || (s[i-1] == '+' || s[i-1] == '>'))){
                cnst *= s[i] - '0';
            }
            else if(s[i] == '-' && s[i + 1] == '>'){
                cnst = 1;
                ind = i + 2;
                break;
            }
        }
        bool b = false;
        for(int i = 0; i < 26; i++){
            if(c1[i] != c2[i]){
                cout<<"NE"<<endl;
                b = true;
                break;
            }
        }
        if(!b) cout<<"DA"<<endl;
    }
}