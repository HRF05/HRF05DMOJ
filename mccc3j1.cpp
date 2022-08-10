#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n, i, j;
	cin>>n>>j>>i;
	if(abs((j * j) - n) < abs((i * i) - n)){
		cout << 1 << endl;
	}
	else{
	    cout << 2 << endl;
    }
}