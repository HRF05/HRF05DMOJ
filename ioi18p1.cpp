#include <queue>
#include <cmath>
#include <vector>
#include <set>
#include <unordered_set>
#include <list>
#include <string>
#include <stack>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <random>
#include <map>
#include <unordered_map>
#include <complex>
#include <algorithm>
#include <climits>
using namespace std;
string guess_sequence(int N){
    string s = "";
    string C = "ABXY";
    if(press("AB")){
        if(press("A")){
            s += 'A';
            C.erase(C.begin() + 0);
        }
        else{
            s += 'B';
            C.erase(C.begin() + 1);
        }
    }
    else{
        if(press("X")){
            s += 'X';
            C.erase(C.begin() + 2);
        }
        else{
            s += 'Y';
            C.erase(C.begin() + 3);
        }
    }
    for(int i = 1; i < N - 1; i++){
        int t = press(s + C[0] + s + C[1] + C[0] + s + C[1] + C[1] + s + C[1] + C[2]);
        if(t == i) s += C[2];
        else if(t == i + 1) s += C[0];
        else if(t == i + 2) s += C[1];
    }
    for(int i = s.length(); i < N; i++){
        int t = press(s + C[0] + s + C[1] + C[0] + s + C[1] + C[2]);
        if(t == i) s += C[2];
        else{
            if(press(s + C[0]) == i + 1) s += C[0];
            else s += C[1];
        }
    }
    return s;
}
