#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int n;
	string s;
	cin>>n>>s;
	if (s == "left") {
		if (n % 2 != 0)
			cout<<"left"<<endl;
		else
			cout<<"right"<<endl;
	}
	else {
		if (n % 2 == 0)
			cout<<"left"<<endl;
		else
			cout<<"right"<<endl;
	}
}