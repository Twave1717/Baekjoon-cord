#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

bool visit[100][100];
char map[100][100];
int r, c;
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
			
			if(map[ny][nx] == '.' && !visit[ny][nx]){
				visit[ny][nx] = 1;
				q.push(make_pair(nx, ny));
			}
			else if(map[ny][nx] == '+'){
				while(map[ny][nx] == '+'){
					nx += dx[i];
					ny += dy[i];
				}
				if(map[ny][nx] == '#'){
					nx -= dx[i];
					ny -= dy[i];
					if(!visit[ny][nx]){
						visit[ny][nx] = 1;
						q.push(make_pair(nx, ny));
					}
				}
				else if(map[ny][nx] == '.' && !visit[ny][nx]){
					visit[ny][nx] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main(){
	scanf("%d %d", &r, &c);
	for(int i = 0; i < r; i++){
		scanf("%s", &map[i][0]);
		for(int j = 0; j < c; j++){
			if(map[i][j] == 'W') q.push(make_pair(j, i));
		}
	}
	
	bfs();
	
	for(int i = 1; i < r-1; i++){
		for(int j = 1; j < c-1; j++){
			if(map[i][j] == '.' && !visit[i][j]) map[i][j] = 'P';
		}
	}
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			printf("%c", map[i][j]);
		}
		puts("");
	}
	
	return 0;
}
