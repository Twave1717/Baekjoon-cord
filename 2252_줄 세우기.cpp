#include <stdio.h>
#include <vector>
using namespace std;

bool visit[32001];
int n, m;
vector<int>v[32001];

void dfs(int idx){
	int s = v[idx].size();
	for(int i = 0; i < s; i++){
		if(!visit[v[idx][i]]){
			visit[v[idx][i]] = 1;
			dfs(v[idx][i]);
		}
	}
	printf("%d ", idx);
	return;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int first, after;
		scanf("%d %d", &first, &after);
		v[after].push_back(first);
	}
	for(int i = 1; i <= n; i++){
		if(!visit[i]){
			visit[i] = 1;
			dfs(i);
		}
	}
	return 0;
}
