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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
#define f first
#define s second
#define INF 2e18
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int a, b, c, d, I = 0;
        cin>>a>>b>>c>>d;
        pii ans[10];
        set<pii> s;
        pii p;
        p.f = c + d;
        p.s = a + b;
        if(!s.count(p)){
            s.insert(p);
            ans[I] = p;
            I++;
        }
        p.f = b + d;
        p.s = a + c;
        if(!s.count(p)){
            s.insert(p);
            ans[I] = p;
            I++;
        }
        p.f = b + c;
        p.s = a + d;
        if(!s.count(p)){
            s.insert(p);
            ans[I] = p;
            I++;
        }
        p.f = a + c;
        p.s = b + d;
        if(!s.count(p)){
            s.insert(p);
            ans[I] = p;
            I++;
        }
        p.f = a + b;
        p.s = c + d;
        if(!s.count(p)){
            s.insert(p);
            ans[I] = p;
            I++;
        }
        p.f = a + d;
        p.s = b + c;
        if(!s.count(p)){
            s.insert(p);
            ans[I] = p;
            I++;
        }
        sort(ans, ans + I);
        cout<<I<<endl;
        for(int i = 0; i < I; i++){
            cout<<ans[i].f<<" "<<ans[i].s<<endl;
        }
    }
}