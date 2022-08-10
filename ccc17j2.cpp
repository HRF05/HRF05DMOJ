#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, k, t = 0;
	string a;
    cin>>n;
    cin>>k;
    t += n;
    for(int i = 1; i <= k; i++)
    {
        t = t + (n * pow(10.0, i));
    }
    cout<<t<<endl;
}
