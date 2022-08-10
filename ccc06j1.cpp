#include <iostream>
using namespace std;


int main()
{
	int a, b, c, d, t = 0;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
		switch(a)
	{ 
	case 1:
		t = t + 461;
		break;
	case 2 :
		t = t + 431;
		break;
	case 3 :
		t = t + 420;
	break;
	}
		switch(b)
	{
	case 1 :
		t = t + 100;
		break;
	case 2 :
		t = t + 57;
		break;
	case 3 :
		t = t + 70;
	break;
	}
		switch(c)
	{
	case 1 :
		t = t + 130;
		break;
	case 2 :
		t = t + 160;
		break;
	case 3 :
		t = t + 118;
	break;
	}
		switch(d)
	{
	case 1 :
		t = t + 167;
		break;
	case 2 :
		t = t + 266;
		break;
	case 3 :
		t = t + 75;
	break;
	}
		cout<<"Your total Calorie count is "<<t<<"."<<endl;
}