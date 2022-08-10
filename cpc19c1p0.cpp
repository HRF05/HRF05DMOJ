#include <iostream>
using namespace std;

int main(){
	string A, B, C, D, x, y;
	cin>>A>>B>>C>>D;
	if((A == "L" && B == "R" ) || (A == "R" && B == "L")){
		cout<<"1 2"<<endl<<"3 4"<<endl;
		return 0;
	}
	else if((A == "L" && C == "R") || (A == "R" && C == "L")){
		cout<<"1 3"<<endl<<"2 4"<<endl;
		return 0;
	}
}