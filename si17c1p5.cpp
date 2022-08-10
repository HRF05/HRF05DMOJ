#include <cmath>
#include <iostream>
using namespace std;
unsigned long long const mod = 1e9;
unsigned long long a, b;
unsigned long long fib(unsigned long long n) {
    unsigned long long m[2][2] = { {b, a}, {a, b} };
    unsigned long long a[2][2] = { {1, 1}, {1, 0} };
    for (unsigned long long i = n; i > 0; i /= 2) {
        unsigned long long A[2][2] = { 0 }, B[2][2] = { 0 };
        if (i % 2 == 1) {
            for (int y = 0; y < 2; y++) {
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < 2; k++) {
                        B[y][j] += m[y][k] * a[k][j];
                        B[y][j] %= mod;
                    }
                }
            }
            for (int j = 0; j < 2; j++)
                for (int y = 0; y < 2; y++) m[j][y] = B[j][y];
        }
        
        for (int y = 0; y < 2; y++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 2; k++) {
                    A[y][j] += a[y][k] * a[k][j];
                    A[y][j] %= mod;
                }
            }
        }
        for (int j = 0; j < 2; j++)
            for (int y = 0; y < 2; y++) a[j][y] = A[j][y];
    }
    return m[0][1];
}
int main() {
    unsigned long long n;
    cin>>a>>b>>n;
    unsigned long long a = fib(n);
    cout<<a<<endl;
}