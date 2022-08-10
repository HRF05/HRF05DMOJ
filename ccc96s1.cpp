#include <iostream>
using namespace std;


int main()
{
    float pd[1000], n;
    int k[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        pd[i] = 0;
        cin >> k[i];
        for (int j = 1; j < k[i]; j++)
        {
            if (k[i] % j == 0 && j != k[i])
            {
                pd[i] = pd[i] + j;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (pd[i] < k[i])
        {
            cout << k[i] << " is a deficient number. " << endl;
        }
        else if (pd[i] > k[i] )
        {
            cout << k[i] << " is an abundant number. " << endl;
        }
        else if (pd[i] == k[i])
        {
            cout << k[i] << " is a perfect number." << endl;
        }
    }
}