#include <iostream>
using namespace std;

int main(){
	int a, b, c = 1;
	cin>>a>>b;
	for(int i = 0; i < b; i++){
		c++;
		for(int y = 2; y < a + 2; y++){
			if(c % 2 == 0){
				if(y % 2 == 0){
					cout<<0;
				}
				else{
					cout<<1;
				}
			}
			else{
				if(y % 2 != 0){
					cout<<0;
				}
				else{
					cout<<1;
				}
			}
			
		}
		cout<<endl;
	}
}