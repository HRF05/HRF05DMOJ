#include <iostream> 
using namespace std;

long long unsigned int mulMod(long long unsigned int a, long long unsigned t, long long unsigned n){
	long long unsigned int res = 0LL;
	a %= n;
	while (t > 0){
		if (t % 2 == 1)
			res = (res + a) % n;
		a = (a * 2) % n;
		t /= 2;
	}
	return res % n;
}
long long unsigned int expMod(long long unsigned int a, long long unsigned t, long long unsigned n){ 
	long long unsigned int res = 1;
	while (t > 0){
		if (t & 1)
			res = mulMod(res, a, n);
		a = mulMod(a, a, n);
		t >>= 1;
	}
	return res % n;
}
bool witness(long long unsigned a, long long unsigned n) {
	long long unsigned u = n - 1, t = 0, xo, xt;
	while(u % 2 == 0){
		u /= 2;
		t++;
	}
	xo = expMod(a, u, n);
	xt = xo;
	for(long long unsigned int i = 0; i < t; i++){
		xt = mulMod(xo, xo, n);
		if (xt == 1 && xo != 1 && xo != n - 1)
			return true;
		xo = xt;
	}
	if(xt != 1)
		return true;
	return false;
}
bool millerRabin(long long unsigned n, int tests){
	long long unsigned a;
	for(int i = 0; i < tests; i++){
		a = (rand() % (n - 1)) + 1;
		if(witness(a, n)){
			return false; // composite
		}
	}
	return true; // prbly prime
}
int main(){
	int tests = 18, n;
	long long unsigned p;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>p;
		if(p < 2){
			cout << "NOT" << endl;
		}
		else if(p < 4){
			cout << "PRIME" << endl;
		}
		else if(millerRabin(p, tests)){
			cout << "PRIME" << endl;
		}
		else{
			cout << "NOT" << endl;
		}
	}
}