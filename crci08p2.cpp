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
struct tri {int f, s, t ;};
#define f first
#define s second
#define pb push_back
#define llu long long unsigned
#define INF 2e18
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int n, r, S[51], R[51], P[51], tot = 0;
char sv[51];
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>r;
    for(int i = 0; i < r; i++){
        cin>>sv[i];
        S[i] = 0; R[i] = 0; P[i] = 0;
    }
    cin>>n;
    for(int i = 0; i < n; i++){
        for(int y = 0; y < r; y++){
            char a;
            cin>>a;
            if(a == sv[y]){
                tot++;
            }
            if(a == 'R'){
                if(sv[y] == 'P') tot+=2;
                R[y]++;
            }
            else if(a == 'S'){
                if(sv[y] == 'R') tot+=2;
                S[y]++;
            }
            else if(a == 'P'){
                if(sv[y] == 'S') tot+=2;
                P[y]++;
            }
        }
    }
    cout<<tot<<endl;
    int btot = 0;
    for(int i = 0; i < r; i++){
        int st = S[i] + P[i] * 2, pt = P[i] + R[i] * 2, rt = R[i] + S[i] * 2;
        if(st >= pt && st >= rt){
            btot+=st;
        }
        else if(rt >= pt && rt >= st){
            btot+=rt;
        }
        else if(pt >= rt && pt >= st){
            btot+=pt;
        }
        
    }
    cout<<btot<<endl;
}