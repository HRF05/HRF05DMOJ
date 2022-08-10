#include <iostream>
#include <set>
#pragma GCC optimize ("O3")
using namespace std;

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
	int n, prev = 0, ans[101];
	multiset<int, greater<int>> a;
	cin>>n;
	for(int i = 0; i < n * n; i++){
		long long t;
		cin >> t;
		a.insert(t);
	}
	int y = 0;
	for(auto i = a.begin(); i != a.end(); i++) {
		if(a.count(*i) % 2 != 0){
			if(*i / 2 != prev){
				ans[y] = *i / 2;
				prev = ans[y];
				y++;
			}
		}
	}
	for(int i = n - 1; i >= 0; i--){
		cout<<ans[i];
		if(i != 0) cout<<" ";
	}
	cout<<endl;
}