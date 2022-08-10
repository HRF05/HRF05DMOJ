#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool getMin(int AL, int BL, string a, string b){
    if(AL > BL){
        return true;
    }
    else if(BL > AL){
        return false;
    }
    else{
        for(int i = 0; i < AL; i++){
            if(a[i] > b[i]){
                return true;
            }
            else if(a[i] < b[i]){
                return false;
            }
        }
    }
}
void add(string sl, string ss){
    string a;
    int c = 0, y = sl.length() - ss.length();
    for(int i = ss.length() - 1; i >= 0; i--){
        int t = (ss[i] - 48) + (sl[i + y] - 48) + c;
        a.push_back(t % 10 + 48);
        c = t / 10;
    }
    for(int i = y - 1; i >= 0; i--){
        int t = (sl[i] - 48) + c;
        a.push_back(t % 10 + 48);
        c = t / 10;
    }

    if(c > 0) a.push_back(c + 48);
    reverse(a.begin(), a.end());
    cout<<a<<endl;
}
void subtract(string sl, string ss){
    string a;
    int c = 0, y = sl.length() - ss.length();
    for(int i = ss.length() - 1; i >= 0; i--){
        if(ss[i] == '-'){
            y--;
            continue;
        }
        else if(sl[i + y] == '-'){
            continue;
        }
        int t = (sl[i + y] - 48) - (ss[i] - 48) - c;
        if(t < 0){
            t += 10;
            c = 1;
        }
        else
            c = 0;
        a.push_back(t + 48);
    }
    for(int i = y-1; i >= 0; i--){
        int t = (sl[i] - 48) - c;
        if(sl[i] == '0' && c){
            a.push_back('9');
            continue;
        }
        if(t > 0 || i > 0)
            a.push_back(t + 48);
        c = 0;
    }
    reverse(a.begin(), a.end());
    bool BOOL = false;
    for(int i = 0; i < a.length(); i++){
        if (a[i] != '0')
            BOOL = true;
        if (BOOL)
            cout << a[i];
    }
    cout << endl;
}
int main(){
    std::ios::sync_with_stdio(false) ; std::cin.tie(0) ; std::cout.tie(0) ;
    int n;
    string a, b;
    cin>>n;
    for(int y = 0; y < n; y++){
        bool sB = false, sA = false;
        cin>>a>>b;
        int AL = a.length(), BL = b.length();
        if(a[0] == '-'){
            a.erase(0, 1);
            sA = true;
            AL -= 1;
        }
        if(b[0] == '-'){
            b.erase(0, 1);
            sB = true;
            BL -= 1;
        }
        if(a == b && sA != sB){
            cout<<0<<endl;
            continue;
        }
        if(sA && !sB){
            if(getMin(AL, BL, a, b)){
                cout << '-';
                subtract(a, b);
            }
            else{
                subtract(b, a);
            }
        }
        else if(sB && !sA){
            if(getMin(BL, AL, b, a)){
                cout << '-';
                subtract(b, a);
            }
            else{
                subtract(a, b);
            }
        }
        else if(!sB && !sA){
            if(AL > BL)
                add(a, b);
            else
                add(b, a);
        }
        else if(sB && sA){
            cout << '-';
            if(AL > BL)
                add(a, b);
            else
                add(b, a);
        }
    }
    
}