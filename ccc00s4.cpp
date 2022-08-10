#include <iostream>
using namespace std;
int main(){
  int x, n, c[10000], p[10000];
  cin>>x>>n;
  for(int i = 0; i < n; i++)
    cin>>c[i];
  p[0] = 0;
  for(int i = 1; i <= x; i++){
    int l = x;
    for(int y = 0; y < n; y++){
      int r = i-c[y];
      if(r < 0) continue;
      l = min(l, p[r] + 1);
    }
    p[i] = l;
  }
  if(p[x] != x)
    cout<<"Roberta wins in "<<p[x]<<" strokes."<<endl;
  else
    cout<<"Roberta acknowledges defeat."<<endl;
}