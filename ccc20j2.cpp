#include <iostream>
using namespace std;



int main()
{
	int p, n, r, add, t;
	cin>>p;
	cin>>n;
	cin>>r;
	t = n;
	for(int i = 0; n <= p; i++)
	{
		add = t * r;
		t = add;
		n = n + add;
		if(n > p)
		{
			cout<<i + 1<<endl;
		}
	}
}