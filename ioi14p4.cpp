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

int valid(int n, int inputSeq[]){
    set<int> s;
    int mi = 0;
    for(int i = 0; i < n; i++){
        if(s.count(inputSeq[i])) return 0;
        s.insert(inputSeq[i]);
        if(inputSeq[i] < inputSeq[mi]) mi = i;
    }
    if(inputSeq[mi] >= n)
        return 1;
    int c = -1;
    for(int i = mi; i < n; i++){
        c++;
        if(inputSeq[i] != inputSeq[mi] + c && s.count(inputSeq[mi] + c)) return 0;
        if(inputSeq[mi] + c == n){
            inputSeq[mi] = 0;
            c = 0;
        }
    }
    for(int i = 0; i < mi; i++){
        c++;
        if(inputSeq[i] != inputSeq[mi] + c && s.count(inputSeq[mi] + c)) return 0;
        
        if(inputSeq[mi] + c == n){
            inputSeq[mi] = 0;
            c = 0;
        }
    }
    return 1;
}

int replacement(int n, int gondolaSeq[], int replacementSeq[]){
    vector<pii> v;
    int ind = -1, ar[100005];
    for(int i = 0; i < n; i++){
        if(gondolaSeq[i] > n) v.pb(mp(gondolaSeq[i], i));
        else{
            ind = i;
        }
    }
    int c = 0;
    sort(v.begin(), v.end());
    if(ind == -1){
        for(int i = 0; i < n; i++){
            ar[i] = i + 1;
        }
    }
    else{
        int t = gondolaSeq[ind];
        for(int i = ind; i < n; i++){
            ar[i] = t + c;
            if(t + c == n){
                t = 0;
                c = 0;
            }
            c++;
        }
        for(int i = 0; i < ind; i++){
            ar[i] = t + c;
            if(t + c == n){
                t = 0;
                c = 0;
            }
            c++;
        }
    }
    ind = 0;
    c = n;
    for(int i = 0; i < v.size(); i++){
        while(ar[v[i].s] != v[i].f){
            c++;
            replacementSeq[ind] = ar[v[i].s]; ind++;
            ar[v[i].s] = c;
            
        }
    }
    return ind;
}
ll mod = 1e9 + 9;
ll expmod(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1) ans *= a;
        a *= a;
        ans %= mod;
        a %= mod;
        b /= 2;
    }
    return ans % mod;
}
int countReplacement(int n, int inputSeq[]){
    if(!valid(n, inputSeq)) return 0;
    vector<ll> v;
    bool B = false;
    ll ans = 1;
    for(int i = 0; i < n; i++){
        if(inputSeq[i] > n) v.pb(inputSeq[i]);
        else B = true;
    }
    if(!B) ans *= n;
    sort(v.begin(), v.end());
    ll c = v.size(), r = n;
    for(ll i = 0; i < v.size(); i++){
        ans *= expmod(c, v[i] - r - 1);
        r = v[i];
        c--;
        ans %= mod;
    }
    return (int)ans;
}