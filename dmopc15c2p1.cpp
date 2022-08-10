#include <iostream>
using namespace std;

int main(){
	int total = 0, swords = 0, n, k;
	cin>>n>>k;
	while(n > 0){
		swords++;n--;
		total++;
		if(swords == k){
			n++;
            swords = 0;
		}
	}
	cout<<total<<endl;
}
