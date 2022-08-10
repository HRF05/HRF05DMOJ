#include <iostream>
#include <set>
using namespace std;
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    set<string> s[400001];
    int n, q;
    cin>>n>>q;
    for (int i = 0; i < q; i++) {
        int a, b;
        string c;
        cin>>a>>b>>c;
        if (a == 1)
            cout<<s[b].count(c)<<endl;
        else
            s[b].insert(c);
    }
}