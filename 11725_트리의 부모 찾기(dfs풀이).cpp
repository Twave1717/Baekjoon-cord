#include <stdio.h>
#include <vector>
using namespace std;

int n, parent[100001];
vector<int>link[100001];

void dfs(int now){
	
	int s = link[now].size();
	
	for(int i = 0; i < s; i++){
		if(parent[link[now][i]] == 0){
			parent[link[now][i]] = now;
			dfs(link[now][i]);
		}
	}
	return;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		link[a].push_back(b);
		link[b].push_back(a);
	}
	
	dfs(1);
	
	for(int i = 2; i <= n; i++){
		printf("%d\n", parent[i]);
	}
	
	return 0;
}
