#include <iostream>
using namespace std;
#define endl "\n"
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, t, w, ans = 0;
    cin>>n>>t>>w;
    long long a[100000];
    for(int i = 0; i <= n; i++){
        a[i] = 0;
    }
    for(int i = 0; i < w; i++){
        int A, b, c;
        cin>>A>>b>>c;
        a[A] += c;
        a[b + 1] -= c;
    }
    for(int i = 1; i <= n; i++){
        a[i] += a[i-1];
        if (a[i] < t) ans++;
    }
    cout<<ans<<endl;
}