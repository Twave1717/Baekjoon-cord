#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main(){
	
	int n, k, idx = 0;
	long long ans = 0;
	vector<pair<int, int> >jew;
	vector<int>bag;
	priority_queue<int>pq;
	
	scanf("%d %d", &n, &k);
	jew.resize(n);
	bag.resize(k);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &jew[i].first, &jew[i].second);
	}
	for(int i = 0; i < k; i++){
		scanf("%d", &bag[i]);
	}
	
	sort(jew.begin(), jew.end());
	sort(bag.begin(), bag.end());
	
	for(int i = 0; i < k; i++){
		
		while(bag[i] >= jew[idx].first && idx < n){
			pq.push(jew[idx++].second);
		}
		
		if(!pq.empty()){
			ans += pq.top();
			pq.pop();
		}
	}
	
	printf("%lld", ans);
	
	return 0;
}
