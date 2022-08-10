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
#define mp make_pair
#define INF 2e18
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int n;
stack<pii> s;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    scan(n);
    for(int i = 0; i < n; i++){
        pii a;
        int ans = 0;
        scan(a.first);
        a.second = 1;
        while(!s.empty() && s.top().first <= a.first){
            a.second+=s.top().second;
            ans+=s.top().second;
            s.pop();
        }
        if(!s.empty())
            ans++;
        s.push(a);
        cout<<ans<<" ";
    }
}