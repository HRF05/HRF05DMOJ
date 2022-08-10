#include <iostream>
#include <cmath>
using namespace std;

int smallfactor(int n){
  for(int i = 2; sqrt(i)< n; i++)
    if(n % i == 0)
      return i;
  return 1;
}
int main(){
  int n, x = 0;
  cin>>n;
  while(n > 1){
    int t = n / smallfactor(n); 
    n-=t, x+=n/t;
  }
  cout<<x<<endl;
}