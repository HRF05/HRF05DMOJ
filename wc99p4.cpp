#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int a[16000]{ 0 }, n;
    a[1] = 1;
	for (int i = 2; i < sqrt(16000); i++)
		for (int y = i * i; y < 16000; y += i) a[y] = 1;
    a[1] = 0;
	while(n != -1){
        cin>>n;
        if(n == -1) return 0;
        for(int i = 1; i * 2 <= n; i++){
            if(a[i] == 0){
                if(a[n-i] == 0){
                    cout<<i<<" "<<n-i<<endl;
                }
            }
        }
    }
}