#include <iostream>
using namespace std;
int main(){
    int x, n, c[1000], p[1000];
    p[999] = 1;
    while(p[999]){
        cin>>x>>n;
        if(!x && !n) return 0;
        for(int i = 0; i < n; i++)
            cin>>c[i];
        p[0] = 0;
        for(int i = 1; i <= x; i++){
            int l = x;
            for(int y = 0; y < n; y++){
                int r = i-c[y];
                if(r < 0) continue;
                l = min(l, p[r] + 1);
            }
            p[i] = l;
        }
        if(p[x] != x)
            cout<<p[x]<<endl;
        else
            cout<<-1<<endl;
    }
}