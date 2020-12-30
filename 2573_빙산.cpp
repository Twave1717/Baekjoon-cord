#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

bool visit[300][300];
int r, c, map[300][300], temp[300][300];
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};

void input(){
	scanf("%d %d", &r, &c);
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
			scanf("%d", &map[i][j]);
	return;
}

void bfs(int x, int y){
	queue<pair<int, int> >q;
	q.push(make_pair(x, y));
	visit[y][x] = 1;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
			if(!visit[ny][nx] && map[ny][nx]){
				visit[ny][nx] = 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
	return;
}

int melt(int x, int y){
	int cnt = 0;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(map[ny][nx] == 0) cnt++;
	}
	return cnt;
}

void solve(){
	int year = 0;
	while(1){
		int land_cnt = 0;
		memset(visit, 0, sizeof(visit));
		memset(temp, 0, sizeof(temp));
		
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				if(map[i][j] > 0 && !visit[i][j]){
					land_cnt++;
					bfs(j, i);
				}
			}
		}
		
		if(land_cnt >= 2){
			printf("%d", year);
			break;
		}
		if(land_cnt == 0){
			printf("0");
			break;
		}
		
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				if(map[i][j]){
					temp[i][j] = map[i][j] - melt(j, i);
					if(temp[i][j] < 0) temp[i][j] = 0;
				}
			}
		}
		
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				map[i][j] = temp[i][j];
			}
		}
		
		year++;
	}
	
	return;
}

int main(){
	input();
	solve();
	return 0;
}
