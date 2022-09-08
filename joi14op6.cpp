#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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

#include "secret.h"

const int MAX = 1e3 + 5;
int ar[MAX][MAX], n, *a;

void f(int l, int h){
    int m = (l + h) / 2;
    ar[m][m] = a[m];
    ar[m+1][m+1] = a[m+1];
    for(int i = m+2; i <= h; i++){
        ar[m+1][i] = Secret(ar[m+1][i-1], a[i]);
    }
    for(int i = m-1; i >= l; i--){
        ar[m][i] = Secret(a[i], ar[m][i+1]);
    }
    if(l < m) f(l, m);
    if(m + 1 < h) f(m+1, h);
}
void Init(int N, int A[]){
    n = N;
    a = A;
    f(0, n-1);
}
int Query(int L, int R){
    int l = 0, h = n - 1;
    while(l < h){
        int m = (l + h) / 2;
        if(m >= L && m < R) return Secret(ar[m][L], ar[m+1][R]);
        else if(m == R) return ar[m][L];
        else if(m < L) l = m + 1;
        else h = m;
    }
    return ar[l][l];
}