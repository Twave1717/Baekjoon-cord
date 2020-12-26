#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

bool visit[1000][1000];
int n, m, map[1000][1000];
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
queue<pair<int, int> >q;

void bfs(){
	
	while(!q.empty()){
	
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
			if(map[ny][nx] == 1 && visit[ny][nx] == 0){
				visit[ny][nx] = 1;
				map[ny][nx] = map[y][x] + 1;
				q.push(make_pair(nx, ny));
			}
		}	
	}
	return;
}

void scan(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 0){
				visit[i][j] = 1;
			}
			else if(map[i][j] == 2){
				map[i][j] = 0;
				visit[i][j] = 1;
				q.push(make_pair(j, i));
			}
		}
	}
	return;
}

void print(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(visit[i][j]) printf("%d ", map[i][j]);
			else printf("-1 ");
		}
		puts("");
	}
	return;
}

int main(){
	scan();
	bfs();
	print();
	
	return 0;
}
