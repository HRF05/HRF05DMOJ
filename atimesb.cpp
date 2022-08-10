#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <complex>
#include <string>
using namespace std;
using cd = complex<double>;
cd a[3000000], b[3000000];
void fft(cd * a, int n){
	if (n <= 1) return;
	cd ao[n >> 1], at[n >> 1];
	for(int i = 0; i < n >> 1; i++){
		ao[i] = a[i << 1];
		at[i] = a[(i << 1) + 1];
	}
	fft(ao, n >> 1);
	fft(at, n >> 1);
	double A = acos(-1) / (n >> 1);
	cd w1(cos(A), sin(A)), x, w(1, 0);
	for(int i = 0; i < n >> 1; i++){
		x = w * at[i];
		a[i] = ao[i] + x;
		a[i + (n >> 1)] = ao[i] - x;
		w = w* w1;
	}
}
void fftinv(cd * a, int n){
	if (n <= 1) return;
	cd ao[n >> 1], at[n >> 1];
	for(int i = 0; i < n >> 1; i++){
		ao[i] = a[i << 1];
		at[i] = a[(i << 1) + 1];
	}
	fftinv(ao, n >> 1);
	fftinv(at, n >> 1);
	double A = acos(-1) / (n >> 1);
	cd w1(cos(A), -sin(A)), x, w(1, 0);
	for(int i = 0; i < n >> 1; i++){
		x = w * at[i];
		a[i] = ao[i] + x;
		a[i + (n >> 1)] = ao[i] - x;
		w = w* w1;
	}
}
string Multiply(string no, string nt){
	if(no == "0" || nt == "0") return "0";
	for(int i = 0; i < no.size(); i++)	a[i] = no[i] - 48;
	for(int i = 0; i < nt.size(); i++)	b[i] = nt[i] - 48;
	int l = 1;
	while(l <= no.length() + nt.length()) l <<= 1;
	fft(a, l);
	fft(b, l);
	for(int i = 0; i <= l; i++) a[i] = a[i] * b[i];
	fftinv(a, l);
	string ans;
	int f = 0;
	vector<int>as;
	for(int i = no.length() + nt.length() - 2; i >= 0; i--) as.push_back(int(a[i].real() / l + 0.5));
	for(auto x : as){
		ans+= to_string((x + f) % 10);
		f = (x + f) / 10;
	}
	if(f > 0) ans += to_string(f);
	reverse(ans.begin(), ans.end());
	return ans;
}
int main(){
	string no, nt;
	cin>>no>>nt;
	cout<<Multiply(no, nt)<<endl;
}