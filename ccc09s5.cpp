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
#define su(x) do{while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48);}while(0)
#define si(x) do{while((x=getchar())<45); _sign=x==45; if(_sign) while((x=getchar())<48); for(x-=48; 48<=(_=getchar()); x=(x<<3)+(x<<1)+_-48); x=_sign?-x:x;}while(0)
#define sc(x) do{while((x=getchar())<33);}while(0)
char _;
int n, w, h, psa[30003][1003], g = 0, ng = 0;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>w>>h>>n;
    for(int i = 0; i < n; i++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        for(int y = 0; y <= c; y++){
            int t=sqrt(c*c-y*y);
            int x = (a-t > 0)? a-t : 1;
            int Y = b - y;
            int X = min(a + t, h + 1);
            int J = min(b + y, w + 1);
            //cout<<x<<" "<<a + t<<"  "<<b + y<<" "<<Y<<endl;
            psa[J][x]+=d;
            psa[J][X+1]-=d;
            if(Y != b + y && Y > 0){
                psa[Y][x]+=d;
                psa[Y][X+1]-=d;
            } 
        }
    }
    for(int i = 1; i <= w; i++){
        for(int y = 1; y <= h; y++){
            psa[i][y] += psa[i][y - 1];
            if(psa[i][y] > g){
                g=psa[i][y]; 
                ng=1;
            }
            else if(psa[i][y] == g) ng++;
            //cout<<psa[i][y]<<" ";
        }
        //cout<<endl;
    }
    cout<<g<<endl;
    cout<<ng<<endl;
}