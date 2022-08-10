#include <iostream>
using namespace std;

int main(){
	int n, m[1000000], q, qa, qb, total, s[1000000];
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>m[i];
	}
	s[0] = m[0];
	for (int i = 1; i < n; i++){
		s[i] = s[i - 1] + m[i];
	}
	cin>>q;
	for(int i = 0; i < q; i++){
		cin>>qa>>qb;
		if (qa > 0){
			total = s[qb] - s[qa - 1];
		}
		else{
			total = s[qb];
		}
		
		cout<<total<<endl;
	}
}