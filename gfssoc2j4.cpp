#include <iostream>
using namespace std;


int main(){
    cin.tie(0); 
    cin.sync_with_stdio(0);
	int n, m[500000], q, qa, qb, s[500000];
	cin>>n>>q;
	s[0] = m[0];
	for (int i = 0; i < n; i++){
		cin>>m[i];
		s[i] = s[i - 1] + m[i];
	}
	for (int i = 0; i < q; i++){
		cin>>qa>>qb;		
		if(qa > 1){
		    cout<<s[n - 1] - (s[qb - 1] - s[qa - 2])<<endl;
		}
		else{
		    cout<<s[n - 1] - s[qb - 1]<<endl;
		}
	}
}