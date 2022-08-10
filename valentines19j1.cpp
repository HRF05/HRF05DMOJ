#include <iostream>
using namespace std;

int main(){
	int N;
	int x[100];
	cin>>N;
	for(int i = 1; i <= N; i++){
		cin>>x[i];
	}
	for(int i = 1; i <= N; i++){
		if(x[i] < 1000){
			cout<<"Newbie"<<endl;
		}
		else if(x[i] < 1200){
			cout<<"Amateur"<<endl;
		}
		else if(x[i] < 1500){
			cout<<"Expert"<<endl;
		}
		else if(x[i] < 1800){
			cout<<"Candidate Master"<<endl;
		}
		else if(x[i] < 2200){
			cout<<"Master"<<endl;
		}
		else if(x[i] < 3000){
			cout<<"Grandmaster"<<endl;
		}
		else if(x[i] < 4000){
			cout<<"Target"<<endl;
		}
		else{
			cout<<"Rainbow Master"<<endl;
		}
	}
	
}