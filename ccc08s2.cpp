#include <iostream>
#include <cmath>
using namespace std;
#define endl "\n"
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int r;
    cin >> r;
    while (r) {
        int p = 0;
        for (int i = 0; i < r; i++)
            p += sqrt(r * r - i * i);
        cout << p * 4 + 1 << endl;
        cin >> r;
    }
}