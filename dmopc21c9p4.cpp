#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
void change(char& c) {
	if (c == 'H') c = 'T';
	else if(c == 'T') c = 'H';
}
int main() {
	int n, m, C = 0;
	cin>>n>>m;
	char a[n][m];
	char d[n];
	for (int i = 0; i < n; i++){
		int R = 0;
		for (int y = 0; y < m; y++){
			cin >> a[i][y];
			if(a[i][y] == 'H'){
			    R++;
			    C++;
			}
		}
		if(R % 2 != 0) d[i] = 'H';
		else d[i] = 'T';
	}
	
	if(C % 2 == 0){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < n; i++){
		if(d[i] == 'H'){
			for(int y = 0; y < m; y++){
				if(a[i][y] == 'H'){
					cout<<i + 1<<" "<<y + 1<<endl;
					if (y > 0) change(a[i][y - 1]);
					if(y < m - 1) change(a[i][y + 1]);
					if (i > 0) change(a[i - 1][y]);
					if(i < n - 1) change(a[i + 1][y]);
					a[i][y] = 'N';
					if (y > 0) y -= 2;
					else y--;
				}
			}
			if (i > 0) change(d[i - 1]);
			if(i < n - 1) change(d[i + 1]);
			d[i] = 'N';
			if (i > 0) i -= 2;
			else i--;
			
		}
	}
}