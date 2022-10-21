#include <iostream>
using namespace std;

int main() {
    int n, k;
    long long unsigned i = 1, t = 0;
    cin>>n>>k;
    while(i  < n){
        cout<<i<<" ";
        t+=i;
        i++;
    } // t = 14
    while (i){
        if((t + i) % k == 0){
            cout<<i<<endl;
            return 0;
        }
        i++;
    }
}