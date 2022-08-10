#include <iostream>
using namespace std;

int main() {
	long long unsigned a, b, g[1500][1500];
	cin >> a >> b;
	for(int i = 0; i < a; i++){
		for(int y = 0; y < b; y++){
			cin >> g[i][y];
			if(y == 0 && i == 0 && g[i][y] == 0){
				g[i][y] = 1;
				continue;
			}
			if(g[i][y] == 0){
				if(i == 0){
					g[i][y] = g[i][y - 1] + 1;
				}
				else if(y!=0){
					if(g[i - 1][y] > g[i][y - 1]){
						g[i][y] = g[i - 1][y] + 1;
					}
					else{
						g[i][y] = g[i][y - 1] + 1;
					}
				}
				else{
					g[i][y] = g[i - 1][y] + 1;
				}
			}
			if(i == 0 && y != 0){
				if(g[i][y] <= g[i][y - 1]){
					cout << -1 << endl;
					return 0;
				}
			}
			else if(y == 0 && i != 0){
				if(g[i][y] <= g[i - 1][y]){
					cout << -1 << endl;
					return 0;
				}
			}
			else if(i != 0 && y != 0){
				if(g[i][y] <= g[i][y - 1] || g[i][y] <= g[i - 1][y]){
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}
	for (int i = 0; i < a; i++){
		for (int y = 0; y < b; y++)	cout << g[i][y] << " ";
		cout << endl;
	}
}