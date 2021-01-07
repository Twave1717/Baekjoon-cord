#include <stdio.h>
#include <vector>
using namespace std;

int n, cost[501], dp[501];
vector<int>v[501];

int max(int a, int b){
	return a > b ? a : b;
}

int dfs(int idx){
	int timeMax = 0;
	int s = v[idx].size();
	for(int i = 0; i < s; i++){
		if(dp[v[idx][i]] == 0){
			dp[v[idx][i]] = dfs(v[idx][i]);
		}
		timeMax = max(timeMax, dp[v[idx][i]]);
	}
	
	return dp[idx] = timeMax + cost[idx];
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &cost[i]);
		while(1){
			int temp;
			scanf("%d", &temp);
			if(temp == -1) break;
			v[i].push_back(temp);
		}
	}
	for(int i = 1; i <= n; i++){
		if(dp[i] == 0){
			dfs(i);
		}
		printf("%d\n", dp[i]);
	}
	return 0;
}
