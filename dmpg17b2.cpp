#include <iostream>
#include <string>
using namespace std;

int main(){
	int i = 0, z = 0, beginB, end;
	string a;
	getline(cin, a);
	while(i >= 0){
		if(z == 0){
			if(a[i] == ','){
				z = 1;
				beginB = i;
			}
		}
		else if(z == 1){
			if(a[i] == '.' || a[i] == '?' || a[i] == '!'){
				end = i;
				i = -2;
			}
		}
		i++;
	}
	a[beginB + 2] = toupper(a[beginB + 2]);
	if(beginB + 1 != end){
		a[0] = tolower(a[0]);
	}
	for(int i = beginB + 2; i < end; i++){
		cout<<a[i];
	}
	for(int i = 0; i < beginB; i++){
		if(end - beginB > 1 && i == 0){
			cout<<" ";
		}
		cout<<a[i];
	}
	cout<<a[end]<<endl;
}