#include <stdio.h>

bool map[1001][1001], visit[1001];
int n, m, cnt;

void dfs(int now){
	
	for(int i = 1; i <= n; i++){
		if(map[now][i] == 1 && visit[i] == 0){
			visit[i] = 1;
			dfs(i);
		}
	}
	return;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
		map[b][a] = 1;
	}
	
	for(int i = 1; i <= n; i++){
		if(visit[i] == 0){
			visit[i] = 1;
			dfs(i);
			cnt++;
		}
	}
	
	printf("%d", cnt);
	
	return 0;
}
