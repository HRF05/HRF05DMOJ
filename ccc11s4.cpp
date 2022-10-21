#include <iostream>
using namespace std;
int b[8], p[8], s[8], f = 0;
void blood(int pa, int bl){
	int t = min(p[pa], b[bl]);
	p[pa] -= t, b[bl] -= t, f += t;
}
int main(){
	for(int i = 0; i < 4; i++) cin>>b[i]>>b[i + 4];
	for(int i = 0; i < 4; i++) cin>>p[i]>>p[i + 4];
	for(int i = 0; i < 8; i++) blood(i, i), s[i] = p[i] - b[i];
	if(s[2] + s[6] > s[1] + s[5]){
    	int t = p[1], r = b[1];
    	b[1] = b[2], p[1] = p[2];
    	b[2] = r, p[2] = t;
    	t = p[5], r = b[5];
    	b[5] = b[6], p[5] = p[6];
    	b[6] = r, p[6] = t;
	}
	for(int i = 0; i < 4; i++) 
		for(int y = i - 1; y >= 0; y--) 
			if(y != 1 || i != 2) blood(i, y);
	for(int i = 4; i < 8; i++)
		for(int y = i - 4; y >= 0; y--)
			if(y != 1 || i != 6) blood(i, y);
	for(int i = 5; i < 8; i++)
		for(int y = i - 1; y >= 4; y--) 
			if(y != 5 || i != 6) blood(i, y);

	cout<<f<<endl;
}