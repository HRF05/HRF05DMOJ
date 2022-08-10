#include <iostream> 
using namespace std;

using ull = unsigned long long;

ull expMod(ull a, ull t, ull n){ // not intended solution
	ull res = 1;
	while (t > 0){
		if (t & 1)
			res = (res * a) % n;
		a = (a * a) % n;
		t >>= 1;
	}
	return res % n;
}
bool witness(ull a, ull n){
	ull u = n - 1, t = 0, xo, xt;
	while(u % 2 == 0){
		u /= 2;
		t++;
	}
	xo = expMod(a, u, n);
	xt = xo;
	for(ull i = 0; i < t; i++){
		xt = (xo * xo) % n;
		if(xt == 1 && xo != 1 && xo != n - 1)
			return true;
		xo = xt;
	}
	if(xt != 1)
		return true;
	return false;
}
bool millerRabin(ull n, int tests){
	ull a;
	for(int i = 0; i < tests; i++){
		a = (rand() % (n - 1)) + 1;
		if(witness(a, n)){
			return false; // composite
		}
	}
	return true; // prbly prime
}
int main(){
	ios_base::sync_with_stdio(false);
	int tests = 6;
	ull b, e;
	cin>>b>>e;
	if(b < 4){
		cout<<2<<endl<<3<<endl;
		b = 4;
	}
	for(ull i = b; i <= e; i++){
		if(millerRabin(i, tests)){
			printf("%d \n", i);
		}
	}
	return 0;
}