#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int a[148734]{ 0 };
	a[1] = 1;
	for (int i = 2; i < sqrt(148734); i++)
		for (int y = i * i; y < 148734; y += i) a[y] = 1;
	int c, x, ans = 0;
	cin>>c>>x;
	for (int i = 1; i <= c; i++){
		if (a[i] == 0){
			ans += (c - i) / x + 1;
            if(c - i > 0)
                ans += (c - i - 1) / x + 1;
			
		}
	}
	cout<<ans<<endl;
}