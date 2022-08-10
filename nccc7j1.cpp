#include <iostream>
using namespace std;

int main(){
	char a; 
	int total = 0;
	for(int i = 0; i < 5; i++){
		cin>>a;
		if(a == 'P'){
			total++;
		}
	}
	cout<<total<<endl;
}