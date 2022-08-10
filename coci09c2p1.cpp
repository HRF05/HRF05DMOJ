#include <iostream>
#include <iomanip>
#include "math.h"
using namespace std;

int main(){
	int N;
	cin >> N;
	int I;
	cin >> I;
	float IB = I - 0.99;
	cout << (int)ceil(IB * N) << endl;
}