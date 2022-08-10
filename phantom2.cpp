#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int a[1000000]{ 0 }, n;
	cin>>n;
	a[1] = 1;
	for(int i = 2; i < sqrt(1000000); i++)
		for(int y = i * i; y < 1000000; y += i) a[y] = 1;
	for(int i = 0; i < n; i++){
		int s, e, c = 0;
		cin>>s>>e;
		for (int i = s; i < e; i++)
			if (a[i] == 0) c++;
		cout<<c<<endl;
	}
}