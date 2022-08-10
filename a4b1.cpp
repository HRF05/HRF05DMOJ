#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int c;
	cin >> c;
	int j, k[100];
	for (j = 0; j < c; j++){
		cin >> k[j];
	}
    for (int i = 0; i < c - 1; i++)
    sort(k, k + c);
    for (j = 0; j < c; j++)
        cout << k[j] << endl;

}