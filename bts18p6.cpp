#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define endl "\n"
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    long long dif0[100001], dif1[100001], dif2[100001];
    cin >> n >> t;
    for (int i = 0; i <= t; i++) {
        dif2[i] = 0;
        dif1[i] = 0;
        dif0[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        long long l, r, a, b, c;
        cin >> l >> r >> a >> b >> c;
        b -= 2 * l * a;
        c -= b * l + a * l * l;
        dif2[r+1] -= a, dif2[l] += a;
        dif1[r+1] -= b, dif1[l] += b;
        dif0[r+1] -= c, dif0[l] += c;
    }
    for (long long i = 1; i <= t; i++) {
        dif2[i] += dif2[i - 1];
        dif1[i] += dif1[i - 1];
        dif0[i] += dif0[i - 1];
        cout << (dif2[i] * (i * i)) + (dif1[i] * i) + dif0[i] << " ";
    }
}

/*
f(x) = a * ((x - l) * (x - l)) + b * (x - l) + c
     = a * (x^2 - 2xl + l^2) + bx - bl + c
     = ax^2 - 2axl + al^2 + bx - bl + c
     = ax^2 - 2axl + bx + al^2 - bl + c
     = (a)x^2 + x(b - 2al) + (al^2 + c - bl)
       dif2      dif1          dif0
*/