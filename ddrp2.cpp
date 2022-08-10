#include <iostream>
using namespace std;

int main(){
	char a, b, c;
	cin>>a>>b>>c;
	if((a == 'L' && c == 'R') && (b != a) && (b != c)){
		cout<<"Crossover"<<endl;
	}
	else if((a == 'R' && c == 'L') && (b != a) && (b != c)){
		cout<<"Crossover"<<endl;
	}
	else if((a == 'U' && c == 'D') && (b != a) && (b != c)){
		cout<<"Candle"<<endl;
	}
	else if((a == 'D' && c == 'U') && (b != a) && (b != c)){
		cout<<"Candle"<<endl;
	}
	else{
		cout<<"Neither"<<endl;
	}
}