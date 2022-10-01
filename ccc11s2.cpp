#include <iostream>
using namespace std;

int main(){
	int n, m = 0, i;
	char a[10000], b[10000];
	cin >> n;
	for (i = 0; i < n; i++) cin >> a[i];
	for (i = 0; i < n; i++){
		cin >> b[i];
		if (a[i] == b[i]) m++;
	}
	cout << m << " ";
}
