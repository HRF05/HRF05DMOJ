#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<int> q;
    int n, l[200000];
    vector<int> s[200000];
    cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>l[i];
        if (!l[i])
            q.push(i);
        for (int y = 0, a; y < l[i]; y++) {
            cin>>a;
            s[a-1].push_back(i);
        }
    }
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        cout << t + 1 << " ";
        for(int T : s[t]) {
            l[T]--;
            if (!l[T])
                q.emplace(T);
        }
    }
    return 0;
}