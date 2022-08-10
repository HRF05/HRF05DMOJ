#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num[2000], total;
	string a;
	for(int i = 0; i < 5; i++){
		cin>>a;
		total = 0;
		for(int y = a.length() - 1; y >= 0; y--){
			if(a[y] == 'I'){
				num[y] = 1;
			}
			else if(a[y] == 'V'){
				num[y] = 5;
			}
			else if(a[y] == 'X'){
				num[y] = 10;
			}
			else if(a[y] == 'L'){
				num[y] = 50;
			}
			else if(a[y] == 'C'){
				num[y] = 100;
			}
			else if(a[y] == 'D'){
				num[y] = 500;
			}
			else if(a[y] == 'M'){
				num[y] = 1000;
			}
		}
		for(int y = a.length() - 1; y >= 0; y--){
			if(num[y] > num[y - 1] && y!= 0){
				total = total + num[y] - (num[y - 1] * 2);
			}
			else{
				total = total + num[y];
			}
		}
		cout<<total<<endl;
	}
}