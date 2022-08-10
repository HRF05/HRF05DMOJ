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
#include <bitset>
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
const int MAXS = 1e8 + 3;
bitset<MAXS> prm;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int N;
    su(N);
    for(int i = 2; i * i < MAXS; i++){
        if(prm[i] == 0){
            for(int y = i * i; y < MAXS; y+=i){
                prm[y] = 1;
            }
        }
    }
    while(N--){
        ll n, seq = INT_MAX, psa[10001], ar[10001];
        pll mseq;
        su(n);
        prm[0] = 1;
        prm[1] = 1;
        for(int i = 1; i <= n; i++){
            su(ar[i]);
            psa[i] = psa[i-1] + ar[i];
            for(int y = i - 2; y >= 0 && i - y < seq; y--){
                if(!prm[psa[i] - psa[y]]){
                    seq = i - y;
                    mseq = mp(y, i);
                }
            }
        }
        if(seq == INT_MAX) cout<<"This sequence is anti-primed.";
        else{
            cout<<"Shortest primed subsequence is length "<<seq<<": ";
            for(int i = mseq.f + 1; i <= mseq.s; i++){
                cout<<ar[i]<<" ";
            }
        } 
        cout<<endl;
    }
}