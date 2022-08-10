#include <iostream>
#include <string>
using namespace std;

int main() {
	int k, n, w = 0;
	string a;
	cin>>n>>k>>a;
	for(int i = 0; i < n; i++){
		if(a[i] == 'U'){
			if(k != 0){
				k--;
			}
		}
		else if(a[i] == 'D'){
			k++;
		}
		if(k == 0){
			w += 1;
		}
	}
	cout<<w<<endl;
}
