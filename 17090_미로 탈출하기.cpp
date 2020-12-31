#include <stdio.h>

bool visit[500][500], escape[500][500];
int r, c, map[500][500];
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};

bool dfs(int x, int y){
	
	int nx = x + dx[map[y][x]];
	int ny = y + dy[map[y][x]];
	
	if(nx < 0 || ny < 0 || nx >= c || ny >= r) return 1;
	else if(visit[ny][nx] == 1) return escape[ny][nx];
	else{
		visit[ny][nx] = 1;
		escape[ny][nx] = dfs(nx, ny);
		return escape[ny][nx];
	}
}

int main(){
	scanf("%d %d", &r, &c);
	char temp[500];
	for(int i = 0; i < r; i++){
		scanf("%s", temp);
		for(int j = 0; j < c; j++){
			if(temp[j] == 'U') map[i][j] = 0;
			else if(temp[j] == 'R') map[i][j] = 1;
			else if(temp[j] == 'D') map[i][j] = 2;
			else if(temp[j] == 'L') map[i][j] = 3;
		}
	}
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(visit[i][j] == 0){
				visit[i][j] = 1;
				escape[i][j] = dfs(j, i);
			}
		}
	}
	
	int cnt = 0;
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			if(escape[i][j] == 1) cnt++;
	
	printf("%d", cnt);
	
	return 0;
}
