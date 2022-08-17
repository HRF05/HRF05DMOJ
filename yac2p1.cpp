#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        long long a, b, c, d;
        cin>>a>>b>>c>>d;
        if((b - a) * (d - c) > a * c){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}