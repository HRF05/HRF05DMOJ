#include <iostream>
using namespace std;

int main()
{
	int C, M, K, m;
	cin>>C>>M>>K;
	if(C > M){
		m = C * K; 
	}
	else if(M > C){
		m = M * K;
	}
	else{
		m = C * K;
	}
	cout<<m<<endl;
}
