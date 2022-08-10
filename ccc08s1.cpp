#include <iostream>
using namespace std;

int main()
{
    string x, ls;
    int y, l = 201;
    while(x != "Waterloo")
    {
        cin >> x;
        cin >> y;
        if (y < l)
        {
            l = y;
            ls = x;
        }
    }
    cout << ls << endl;
}