#include <iostream>
using namespace std;

int main(){
    double a, b, c, d, e, f, m = 0;
    cin>>a>>b;
    for (int i = 0; i < a; i++){
        cin>>c>>d;
        e = (d / 100) * c;
        f = c - e;
        if (f <= b) m++;
    }
    cout<<m<<endl;
}