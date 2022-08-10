#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int find_subset(int l, int u, int w[], int n, int result[]){ // 200001
	int p = 0;
	pair<int, int> t[200001];
	long long k[200001];
	for(int i = 0; i < n; i++){
		t[i].first = w[i];
		t[i].second = i;
	}

	sort(t, t + n);
	k[0] = t[0].first;
	for (int i = 1; i < n; i++)
		k[i] = k[i - 1] + t[i].first;
	for(int i = 1; i <= n; i++){
		if(k[i - 1] <= u && k[n - 1] - k[n - i - 1] >= l){
			p = i;
			break;
		}
	}
	if(p == 0){
		return 0;
	}
	queue<int> q;
	int sum = k[p - 1], g = n - 1, s = 0;
	for(int i = 0; i < p; i++){
		q.push(t[i].second);
	}
	while(g >= 0){
		if(sum >= l && sum <= u){
			for(int i = 0; i < p; i++){
				result[i] = q.front();
				q.pop();
			}
			return p;
		}
		else{
			sum -= t[s].first;
			sum += t[g].first;
			q.pop();
			q.push(t[g].second);
			g--;
			s++;
		}
	}
	return 0;
}