#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, start;
bool map[1001][1001], visit[1001];
queue<int>q;

void dfs(int now){
	
	printf("%d ", now);
	
	for(int i = 1; i <= n; i++){
		if(map[now][i] == 1 && visit[i] == 0){
			visit[i] = 1;
			dfs(i);
		}
	}
	return;
}

void bfs(){
	
	printf("%d ", start);
	visit[start] = 1;
	q.push(start);
	
	while(!q.empty()){
		
		int now = q.front();
		q.pop();
		
		for(int i = 1; i <= n; i++){
			if(map[now][i] == 1 && visit[i] == 0){
				printf("%d ", i);
				visit[i] = 1;
				q.push(i);
			}
		}
	}
	return;
}

int main(){
	scanf("%d %d %d", &n, &m, &start);
	for(int i = 0; i < m; i++){
		int a, b;	scanf("%d %d", &a, &b);
		map[a][b] = 1;
		map[b][a] = 1;
	}
	
	visit[start] = 1;
	dfs(start);
	puts("");
	memset(visit, 0, sizeof(visit));
	bfs();
	
	return 0;
}
