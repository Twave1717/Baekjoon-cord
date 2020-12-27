#include <stdio.h>

int n, mx, map[500][500], dp[500][500];
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};

int great(int a, int b){
	return a > b ? a : b;
}

int dfs(int x, int y){
	
	// 4 방향 중 가장 오래 살 수 있는 일 수 저장. (기본적으로 하루는 살 수 있음) 
	int most = 1;
	
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		// 대나무가 더 많은 방향임. 
		if(map[y][x] < map[ny][nx]){
			if(dp[ny][nx] == 0){
				// 처음 가보는 방향이라면 dfs로 탐색. 
				most = great(most, 1 + dfs(nx, ny));
			}
			else{
				// 이미 탐색한적이 있다면 그냥 그 값을 가져옴.
				most = great(most, 1 + dp[ny][nx]);
			}
		}
	}
	
	dp[y][x] = most;
	
	if(mx < dp[y][x]) mx = dp[y][x];
	
	// 24줄에 보내줄 값 리턴. 
	return dp[y][x];
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			scanf("%d", &map[i][j]);
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(dp[i][j] == 0){
				dp[i][j] = 1; // 자기자신은 탐색 X 
				dfs(j, i);
			}
	
	printf("%d", mx);
	
	return 0;
}
