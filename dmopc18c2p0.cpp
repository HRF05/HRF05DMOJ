#include <iostream>
using namespace std;

int main(){
	int R, a, N;
	cin>>N>>a>>R;
	int i = R / a;
	if(i > N){
		i = N;
	}
	cout<<i<<endl;
}