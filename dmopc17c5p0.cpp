#include <iostream>
using namespace std;

int main(){
	int b, p;
	string v;
	cin>>b>>p>>v;
	int bp = b / p;
	if (bp >= 5 && v == "N"){
		cout<<"A"<<endl;
	}
	else if (bp >= 5 && v == "Y"){
		cout<<"B"<<endl;
	}
	else if (bp < 5 && bp > 1 && v == "N"){
		cout<<"C"<<endl;
	}
	else if (bp < 5 && bp > 1 && v == "Y"){
		cout<<"D"<<endl;
	}
	else if (bp < 2){
		cout<<"NO PIZZA"<<endl;
	}
}
