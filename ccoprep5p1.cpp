#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#include <iostream>
#include <stack>
using namespace std;
int w, h, ans = 0, n, he[1000];;
char r;
stack<int> s;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int N = 0; N < n; N++){
        ans = 0;
        cin>>w>>h;
        for(int i = 0; i < w; i++){
            for(int y = 0; y < h; y++){
                cin>>r;
                if(r == 'F'){
                    if(!i) he[y] = 0;
                    he[y]++;
                }
                else{
                    he[y] = 0;
                }
            }
            for(int y = 0; y < h; y++){
                while(!s.empty() && he[s.top()] > he[y]){
                    int H = he[s.top()]; s.pop();
                    int W = (s.empty() ? 0: s.top() + 1);
                    ans = max(ans, H * (y - W));
                }
                s.push(y);
            }
            while(!s.empty()){
                int H = he[s.top()]; s.pop();
                int W = (s.empty() ? 0: s.top() + 1);
                ans = max(ans, H * (h - W));
            }
        }
        cout<<ans * 3<<endl;
    }
}