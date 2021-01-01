#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
int r, c, dist, temp[2];
char map[50][50];
queue<pair<int, int> >water;
queue<pair<int, int> >mole;

void bfs(){
	
	while(!mole.empty()){
		
		dist++;
		
		int s = water.size();
		for(int i = 0; i < s; i++){
			int x = water.front().first;
			int y = water.front().second;
			water.pop();
			
			for(int j = 0; j < 4; j++){
				int nx = x + dx[j];
				int ny = y + dy[j];
				
				if(nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
				
				if(map[ny][nx] == '.' || map[ny][nx] == 'S'){
					map[ny][nx] = '*';
					water.push(make_pair(nx, ny));
				}
			}
		}
		
		s = mole.size();
		for(int i = 0; i < s; i++){
			int x = mole.front().first;
			int y = mole.front().second;
			mole.pop();
			
			for(int j = 0; j < 4; j++){
				int nx = x + dx[j];
				int ny = y + dy[j];
				
				if(nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
				
				if(map[ny][nx] == '.'){
					map[ny][nx] = 'S';
					mole.push(make_pair(nx, ny));
				}
				else if(map[ny][nx] == 'D'){
					return;
				}
			}
		}
	}
	
	dist = -1;
	return;
}

int main(){
	scanf("%d %d", &r, &c);
	for(int i = 0; i < r; i++){
		scanf("%s", &map[i][0]);
		for(int j = 0; j < c; j++){
			if(map[i][j] == '*') water.push(make_pair(j, i));
			if(map[i][j] == 'S') mole.push(make_pair(j, i));
		}
	}
	
	bfs();
	
//	for(int i = 0; i < r; i++){
//		puts("");
//		for(int j = 0; j < c; j++)
//			printf("%c", map[i][j]);
//	}
	
	if(dist == -1) printf("KAKTUS");
	else printf("%d", dist);
	
	return 0;
}
