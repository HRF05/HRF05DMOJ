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
#define fs first
#define se second
#define pb push_back
#define mp make_pair
#define INF 2e18
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int w, h, ar[1003][1003], he[1003], ans = 0;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>w>>h;
    for(int i = 0; i < w; i++){
        for(int y = 0; y < h; y++){
            cin>>ar[i][y];
        }
    }
    for(int i = 0; i < w - 1; i++){
        for(int y = 0; y < h - 1; y++){
            if(ar[i][y] + ar[i + 1][y + 1] <= ar[i][y + 1] + ar[i + 1][y]){
                he[y]++;
            }
            else{
                he[y] = 0;
            }
        }
        stack<int> s;
        for(int y = 0; y < h; y++){
            while(!s.empty() && he[y] < he[s.top()]){
                int H = he[s.top()]; s.pop();
                int W = s.empty()? -1: s.top();
                ans = max(ans, (H + 1) * (y - W));
            }
            s.push(y);
        }
        while(!s.empty()){
            int H = he[s.top()]; s.pop();
            int W = s.empty()? -1: s.top();
            ans = max(ans, (H + 1) * (h - W));
        }
    }
    cout<<ans<<endl;
}