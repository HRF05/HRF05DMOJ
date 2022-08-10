#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main(){
	int a[10000000]{ 0 }, n;
	cin >> n;
	a[1] = 1;
	for(int i = 2; i < sqrt(10000000); i++)
		for(int y = i * i; y < 10000000; y += i) a[y] = 1;
	vector<int> prime;
	for(int i = 2; i < 10000000; i++){
		if(a[i] == 0)
			prime.push_back(i);
	}
	int ak[10000000]{0};
	for(int i = 0; i < size(prime); i++){
	    for(int y = prime[i]; y < 10000002; y=y+prime[i])
	        ak[y]++;
	}
	for(int i = 0; i < n; i++){
		int s, e, k, ans = 0;
		cin >> s >> e >> k;
		for(int y = s; y <= e; y++){
		    if(ak[y] == k) ans++;
		}
		cout<<"Case #"<<i + 1<<": "<<ans<<endl;
	}
}