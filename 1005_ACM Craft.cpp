#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

bool visit[1001];
int n, k, find, cost[1001];
vector<int>parent[1001];

int max(int a, int b){
	return a > b ? a : b;
}

int dfs(int now, int sum){
	
	visit[now] = 1;
	int s = parent[now].size();
	
	int time_cnt = 0;
	for(int i = 0; i < s; i++){
		if(!parent[parent[now][i]].empty() && !visit[parent[now][i]]){
			cost[parent[now][i]] = dfs(parent[now][i], cost[parent[now][i]]); 
		}
		time_cnt = max(time_cnt, cost[parent[now][i]]);
	}
	
	return sum + time_cnt;
}

void input(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d", &cost[i]);
	}
	for(int i = 0; i < k; i++){
		int first, after;
		scanf("%d %d", &first, &after);
		parent[after].push_back(first);
		}
	scanf("%d", &find);
	
	return;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		input();
		
		printf("%d\n", dfs(find, cost[find]));
		
		for(int i = 1; i <= n; i++){
			parent[i].clear();
		}
		memset(visit, 0, sizeof(visit));
	}
	return 0;
}
