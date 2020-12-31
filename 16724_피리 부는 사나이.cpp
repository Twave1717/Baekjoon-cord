#include <stdio.h>

bool visit[1000][1000], safe[1000][1000];
int r, c, safeZone_cnt, map[1000][1000];
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};

void input(){
	scanf("%d %d", &r, &c);
	char temp[1000];
	for(int i = 0; i < r; i++){
		scanf("%s", temp);
		for(int j = 0; j < c; j++){
			if(temp[j] == 'U') map[i][j] = 0;
			else if(temp[j] == 'R') map[i][j] = 1;
			else if(temp[j] == 'D') map[i][j] = 2;
			else if(temp[j] == 'L') map[i][j] = 3;
		}
	}
	return;
}

bool dfs(int x, int y){
	
	int nx = x + dx[map[y][x]];
	int ny = y + dy[map[y][x]];
	
	if(visit[ny][nx] == 0){ // 방문하지 않은곳. 
		visit[ny][nx] = 1;
		safe[y][x] = dfs(nx, ny);
		return safe[y][x];
	}
	else if(visit[ny][nx] == 1 && safe[ny][nx] == 0){ // 방문했지만 safeZone과 연결되지 않은곳. 
		safe[y][x] = 1;
		safeZone_cnt++;
		return safe[y][x];
	}
	else if(visit[ny][nx] == 1){ // 방문했고 safeZone과 연결된곳. 
		safe[y][x] = safe[ny][nx];
		return safe[ny][nx];
	}
}

void solve(){
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(!visit[i][j]){
				visit[i][j] = 1;
				safe[i][j] = dfs(j, i);
			}
		}
	}
	
	printf("%d", safeZone_cnt);
	return;
}

int main(){
	input();
	solve();
	return 0;
}
