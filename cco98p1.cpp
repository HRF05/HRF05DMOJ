#include <iostream>
using namespace std;
string fib[201];
string fibonacci(int n) {
    string sl = fib[n - 1], ss = fib[n - 2], a;
    int c = 0, y = sl.length() - ss.length();
    for (int i = ss.length() - 1; i >= 0; i--) {
        int t = (ss[i] - 48) + (sl[i + y] - 48) + c;
        a.push_back(t % 10 + 48);
        c = t / 10;
    }
    for (int i = y - 1; i >= 0; i--) {
        int t = (sl[i] - 48) + c;
        a.push_back(t % 10 + 48);
        c = t / 10;
    }

    if (c > 0) a.push_back(c + 48);
    reverse(a.begin(), a.end());
    return a;
}
int main() {
    int f = 1;
    fib[0] = "0", fib[1] = "1", fib[2] = "1";
    for (int i = 3; i <= 200; i++) {
        fib[i] = fibonacci(i);
    }
    while (f) {
        cin >> f;
        if (f == 0) return 0;
        cout << fib[f] << endl;
    }
}