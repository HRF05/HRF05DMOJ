#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;
#define int long long unsigned
int mulmod(int a, int b, int m){
    int ans = 0;
    a %= m;
    while(b){
        if (b % 2)
            ans += a % m;
        a = a * 2 % m;
        b /= 2;
    }
    return ans % m;
}
signed main(){
    int n, m, t = 0;
    cin>>n>>m;
    for(int i = 0; i < n; i++){
        int a, b;
        cin>>a>>b;
        t += mulmod(a, b, m);
    }
    cout<<t % m<<endl;
}