#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

char maze[1000][1000]; 
int r, c;
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
queue<pair<int, int> >person, fire;

int bfs(){
	
	int dist = 0;
	
	while(!person.empty()){
		
		dist++;
		
		int s = fire.size();
		for(int i = 0; i < s; i++){
			int x = fire.front().first;
			int y = fire.front().second;
			fire.pop();
			
			for(int j = 0; j < 4; j++){
				int nx = x + dx[j];
				int ny = y + dy[j];
				
				if(nx < 0 || ny < 0 || nx >= c || ny > r) continue;
				if(maze[ny][nx] == '.' || maze[ny][nx] == 'J'){
					maze[ny][nx] = 'F';
					fire.push(make_pair(nx, ny));
				}
			}
		}
		
		s = person.size();
		for(int i = 0; i < s; i++){
			int x = person.front().first;
			int y = person.front().second;
			person.pop();
			
			for(int j = 0; j < 4; j++){
				int nx = x + dx[j];
				int ny = y + dy[j];
				
				if(nx < 0 || ny < 0 || nx >= c || ny >= r){
					return dist;
				}
				if(maze[ny][nx] == '.'){
					maze[ny][nx] = 'J';
					person.push(make_pair(nx, ny));
				}
			}
		}
	}
	return -1;
}

int main(){
	scanf("%d %d", &r, &c);
	for(int i = 0; i < r; i++){
		scanf("%s", &maze[i][0]);
		for(int j = 0; j < c; j++){
			if(maze[i][j] == 'J') person.push(make_pair(j, i));
			if(maze[i][j] == 'F') fire.push(make_pair(j, i));
		}
	}
	
	int ans = bfs();
	
	if(ans == -1) printf("IMPOSSIBLE");
	else printf("%d", ans);
	
	return 0;
}
