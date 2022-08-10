#include <iostream>
using namespace std;

int main(){
	long long n, i[100000], s = 1000000000;
	cin>>n;
	for(int j = 0; j < n; j++){
		cin>>i[j];
		if(i[j] < s){
			s = i[j];
		}
	}
	cout<<s<<endl;
}