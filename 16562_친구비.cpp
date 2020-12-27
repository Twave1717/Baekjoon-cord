#include <stdio.h>
#include <vector>
using namespace std;

int n, m, money, sum;
int cost[10001];
bool visit[10001];
vector<int>v[10001];

int min(int a, int b){
	return a > b ? b : a;
}

int dfs(int now){
	
	int result = cost[now];
	visit[now] = 1;
	int s = v[now].size();
	
	for(int i = 0; i < s; i++){
		if(visit[v[now][i]] == 0){
			result = min(result, dfs(v[now][i]));
		}
	}
	
	return result;
}

int main(){
	scanf("%d %d %d", &n, &m, &money);
	for(int i = 1; i <= n; i++){
		scanf("%d", &cost[i]);
	}
	int a, b;
	for(int i = 0; i < m; i++){
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i = 1; i <= n; i++){
		if(visit[i] == 0){
			sum += dfs(i);
			if(sum > money) break;
		}
	}
	
	if(sum > money){
		printf("Oh no");
		return 0;
	}
	else{
		printf("%d", sum);
	}
	
	return 0;
}
