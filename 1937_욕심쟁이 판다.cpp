#include <stdio.h>

int n, mx, map[500][500], dp[500][500];
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};

int great(int a, int b){
	return a > b ? a : b;
}

int dfs(int x, int y){
	
	// 4 ���� �� ���� ���� �� �� �ִ� �� �� ����. (�⺻������ �Ϸ�� �� �� ����) 
	int most = 1;
	
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		// �볪���� �� ���� ������. 
		if(map[y][x] < map[ny][nx]){
			if(dp[ny][nx] == 0){
				// ó�� ������ �����̶�� dfs�� Ž��. 
				most = great(most, 1 + dfs(nx, ny));
			}
			else{
				// �̹� Ž�������� �ִٸ� �׳� �� ���� ������.
				most = great(most, 1 + dp[ny][nx]);
			}
		}
	}
	
	dp[y][x] = most;
	
	if(mx < dp[y][x]) mx = dp[y][x];
	
	// 24�ٿ� ������ �� ����. 
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
				dp[i][j] = 1; // �ڱ��ڽ��� Ž�� X 
				dfs(j, i);
			}
	
	printf("%d", mx);
	
	return 0;
}
