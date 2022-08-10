#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    cin.tie(0); cin.sync_with_stdio(0);
    int n, m;
    cin>>n>>m;
    vector<vector<int>> l(n);
    double dp[1000001] { 0 };
    dp[0] = 1;
    for (int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        l[a - 1].push_back(b - 1);
    }
    for (int i = 0; i < n; i++){
        int t = l[i].size();
        if (t != 0){
            for (int y : l[i]){
                dp[y] += double(dp[i] / t);
            }
        }
        else{
            cout << setprecision(9) << dp[i] << endl;
        }
    }
}