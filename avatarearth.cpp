#include <iostream>
using namespace std;
int main(){
	int x, y, x1, x2, y1, y2;
	bool xt = false, yt = false;
	cin>>x>>y>>x1>>y1>>x2>>y2;
	if(x > x1 && x < x2){
		xt = true;
	}
	if(y > y1 && y < y2){
		yt = true;
	}
	if(xt && yt){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
}