#include <iostream>
using namespace std;

int main()
{
	int n, r, i;
	cin>>n>>r;
	for(int j = 0; j < n - 1; j++){
		cin>>i;
		if(i >= r){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	return 0;
}