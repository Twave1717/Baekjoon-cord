#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

char map[1000][1000];
int w, h;
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
queue<pair<int, int> >human, fire;

int bfs(){
	
	int dist = 0;
	while(!human.empty()){
		
		dist++;
		
		int fs = fire.size();
		for(int i = 0; i < fs; i++){
			int x = fire.front().first;
			int y = fire.front().second;
			fire.pop();
			
			for(int j = 0; j < 4; j++){
				int nx = x + dx[j];
				int ny = y + dy[j];
				
				if(nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
				if(map[ny][nx] == '.' || map[ny][nx] == '@'){
					map[ny][nx] = '*';
					fire.push(make_pair(nx, ny));
				}
			}
		}
		
		int hs = human.size();
		for(int i = 0; i < hs; i++){
			int x = human.front().first;
			int y = human.front().second;
			human.pop();
			
			for(int j = 0; j < 4; j++){
				int nx = x + dx[j];
				int ny = y + dy[j];
				
				if(nx < 0 || ny < 0 || nx >= w || ny >= h){
					return dist;
				}
				if(map[ny][nx] == '.'){
					map[ny][nx] = '@';
					human.push(make_pair(nx, ny));
				}
			}
		}
	}
	
	return -1;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &w, &h);
		for(int i = 0; i < h; i++){
			scanf("%s", &map[i][0]);
			for(int j = 0; j < w; j++){
				if(map[i][j] == '*') fire.push(make_pair(j, i));
				if(map[i][j] == '@') human.push(make_pair(j, i));
			}
		}
		
		int ans = bfs();
		if(ans == -1) puts("IMPOSSIBLE");
		else printf("%d\n", ans);
		
		while(!fire.empty()) fire.pop();
		while(!human.empty()) human.pop();
	}
	return 0;
}
