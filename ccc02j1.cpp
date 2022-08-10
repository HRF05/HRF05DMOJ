#include <iostream>
using namespace std;

int main()
{
	int n;
	bool tr = false, br = false, tl = false, bl = false, t = false, b = false, m = false;
	cin >> n;
	switch(n)
	{
	case 0 :
	t = true;
	tr = true;
	tl = true;
	br = true;
	bl = true;
	b = true;
	break;
	case 1 :
	tr = true;
	br = true;
	break;
	case 2 :
	t = true;
	tr = true;
	m = true;
	bl = true;
	b = true;
	break;
	case 3 :
	t = true;
	tr = true;
	m = true;
	br = true;
	b = true;
	break;
	case 4 :
	tr = true;
	tl = true;
	m = true;
	br = true;
	break;
	case 5 : 
	t = true;
	tl = true;
	m = true;
	br = true;
	b = true;
	break;
	case 6 :
	t = true;
	tl = true;
	m = true;
	bl = true;
	br = true;
	b = true;
	break;
	case 7 :
	t = true;
	tr = true;
	br = true;
	break;
	case 8 :
	t = true;
	tr = true;
	tl = true;
	m = true;
	br = true;
	bl = true;
	b = true;
	break;
	case 9 :
	t = true;
	tl = true;
	tr = true;
	br = true;
	m = true;
	b = true;
	break;
	}
	if(t == true)
	{
		cout<<" * * *"<<endl;
	}
	else
	{
		cout<<endl;
	}
	if(tr == true && tl == true)
	{
		cout<<"*     *"<<endl<<"*     *"<<endl<<"*     *"<<endl;
	}
	else if(tl == true)
	{
		cout<<"*"<<endl<<"*"<<endl<<"*"<<endl;
	}
	else if(tr == true)
	{
		cout<<"      *"<<endl<<"      *"<<endl<<"      *"<<endl;
	}
	if(m == true)
	{
		cout<<" * * *"<<endl;
	}
	else
	{
		cout<<endl;
	}
	if(br == true && bl == true)
	{
		cout<<"*     *"<<endl<<"*     *"<<endl<<"*     *"<<endl;
	}
	else if(bl == true)
	{
		cout<<"*"<<endl<<"*"<<endl<<"*"<<endl;
	}
	else if(br == true)
	{
		cout<<"      *"<<endl<<"      *"<<endl<<"      *"<<endl;
	}
	if(b == true)
	{
		cout<<" * * *"<<endl;
	}
	else
	{
		cout<<endl;
	}
}