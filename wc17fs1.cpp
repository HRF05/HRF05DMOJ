#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
  int n, m[100000], c[100000];
  cin>>n;
  for(int i = 0; i < n; i++)
    cin>>m[i];
  for(int i = 0; i < n; i++)
    cin>>c[i];
  sort(m, m + n);
  sort(c, c + n);
  int l = INT16_MIN;
  for(int i = 0; i < n; i++)    l = max(abs(m[i] - c[i]), l);
  cout<<l<<endl;
}