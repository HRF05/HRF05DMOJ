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
#include <utility>
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
int n, ar[1000001], oi, ti, aro[1000001], art[1000001];
void swa(int &C, int &B)
{
    C=C+B;
    B=C-B;
    C=C-B;
}
void maake(int strt, bool o, bool C){
    int swp = -1;
    int y = 0;
    for(int i = strt; i < n; i++, y++){
        if(o){
            aro[y] = ar[i];
            if(aro[y] == 2) swp = y;
        } 
        else{
            art[y] = ar[i];
            if(art[y] == 1) swp = y;
        } 
    }
    for(int i = 0; i < strt; i++, y++){
        if(o){
            aro[y] = ar[i];
            if(aro[y] == 2) swp = y;
        }
        else{
            art[y] = ar[i];
            if(art[y] == 1) swp = y;
        }
    }
    if(C) return;
    if(o && aro[swp] == 2 && aro[1] != 2){
        swa(aro[1], aro[swp]);
    }
    else if(!o && art[swp] == 1 && art[0] != 1){
        swa(art[0], art[swp]);
    }
}
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    su(n);
    for(int i = 0; i < n; i++){
        su(ar[i]);
        if(ar[i] == 1) oi = i;
        else if(ar[i] == 2) ti = i;
    }
    if(ti - 1 == oi || (oi == n-1 && ti == 0)){
        maake(oi, true, true);
        for(int i = 0; i < n; i++){
            if(aro[i] != i + 1){
                int t = i + 1;
                for(int y = i + 1; y < n; y++){
                    if(aro[y] == i + 1){
                        t = y;
                        break;
                    } 
                }
                swap(aro[i], aro[t]);
                break;
            }
        }
        for(int i = 0; i < n; i++){
            cout<<aro[i]<<" ";
        }
        cout<<endl;
    }
    else{
        swa(ar[ti], ar[oi]);
        maake(ti, false, true);
        swa(ar[ti], ar[oi]);
        maake(oi, true, false);

        int B = 0;
        for(int i = 0; i < n; i++){
            if(art[i] < aro[i]){
                B = 1;
                break;
            }
            if(aro[i] < art[i]){
                B = 2;
                break;
            }
        }
        if(ti == 0) ti = n;
        
        if(B == 1){
            swap(aro, art);
        }
        maake(ti - 1, false, false);
        B = 0;
        for(int i = 0; i < n; i++){
            if(art[i] < aro[i]){
                B = 2;
                break;
            }
            if(aro[i] < art[i]){
                B = 1;
                break;
            }
        }
        if(B == 1){
            for(int i = 0; i < n; i++){
                cout<<aro[i]<<" ";
            }
            cout<<endl;
        }
        else{
            for(int i = 0; i < n; i++){
                cout<<art[i]<<" ";
            }
            cout<<endl;
        }
    }
}