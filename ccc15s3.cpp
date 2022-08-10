#include <iostream>
#include <set>
using namespace std;
int main() {
  int n, p, a, ans = 0;
  set<int, greater<int>> s;
  cin>>n>>p;
  for(int i = 1; i <= n; i++)
    s.insert(i);
  for(int i = 0; i < p; i++){
    cin>>a;
    auto n = s.lower_bound(a);
    if(n != s.end()){
      ans++;
      s.erase(n);
    }
    else{
      cout<<endl;
      break;
    }
  }
  cout<<ans<<endl;
}