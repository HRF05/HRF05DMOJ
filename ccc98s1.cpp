#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        string s;
        getline(cin, s);
        int c = 0;
        for (int y = 0; y < s.length(); y++) {
            if (s[y] != ' ') {
                c++;
            }
            if (s[y + 1] == ' ' || y == s.length() - 1) {
                if (c == 4) {
                    for (int z = y - 3; z <= y; z++) {
                        s[z] = '*';
                    }
                }
                c = 0;
            }

        }
        cout << s << endl;
    }
    return 0;
}