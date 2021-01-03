#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int r, c;
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
bool visit[301][301];
char room[301][301];
queue<pair<int, int> >jump, nextJump;

void bfs(){
	int cnt = 0;
	while(1){
		cnt++;
		while(!jump.empty()){
			int x = jump.front().first;
			int y = jump.front().second;
			jump.pop();
			
			for(int i = 0; i < 4; i++){
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if(nx < 1 || ny < 1 || nx > c || ny > r) continue;
				
				if(room[ny][nx] == '#'){
					printf("%d", cnt);
					return;
				}
				if(room[ny][nx] == '1'){
					room[ny][nx] = '0';
					visit[ny][nx] = 1;
					nextJump.push(make_pair(nx, ny));
				}
				if(room[ny][nx] == '0' && !visit[ny][nx]){
					visit[ny][nx] = 1;
					jump.push(make_pair(nx, ny));
				}
			}
		}
		while(!nextJump.empty()){
			jump.push(make_pair(nextJump.front().first, nextJump.front().second));
			nextJump.pop();
		}
	}
}

int main(){
	scanf("%d %d", &r, &c);
	int a, b, trash;
	scanf("%d %d %d %d", &a, &b, &trash, &trash);
	visit[b][a] = 1;
	jump.push(make_pair(b, a));
	for(int i = 1; i <= r; i++){
			scanf("%s", &room[i][1]);
	}
	
	bfs();
	return 0;
}
