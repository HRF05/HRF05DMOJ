#include <iostream>
using namespace std;

int main() {
    int n, t, max = 0;
    unsigned long long a[2000001]{ 0 }, l = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        a[t]++;
        if (t > max) max = t;
    }
    for (int i = 1; i <= max; i++) {
        for (int y = i + i; y <= max; y += i)
            if (a[y]) a[i] += a[y];
        if (a[i] > 1 && a[i] * i > l) l = a[i] * i;
    }
    cout << l << endl;
}