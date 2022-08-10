#include <iostream>
using namespace std;

int main(){
	int c, k[100];
	cin>>c;
	for(int j = 0; j < c; j++){
		cin>>k[j];
	}
	for(int y = 0; y < c; y++){
		cout<<k[y]<< " ";
	}
	cout<<endl;
	for(int i = 0; i < c - 1; i++){
		for(int j = 0; j < c - i - 1; j++){
			if (k[j] > k[j + 1]){
				int t = k[j];
				k[j] = k[j + 1];
				k[j + 1] = t;
				for(int y = 0; y < c; y++){
					cout << k[y] << " ";
				}
				cout<<endl;
			}
		}
	}
}