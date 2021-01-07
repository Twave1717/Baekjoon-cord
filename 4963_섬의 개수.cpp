#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

struct loc{
	int x;
	int y;
};

int r, c, sea[50][50];
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
queue<loc>q;

void bfs(){
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		q.pop();
		
		for(int i = 0; i < 8; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
			if(sea[ny][nx] == 1){
				sea[ny][nx] = 0;
				q.push({nx, ny});
			}
		}
	}
	return;
}

int main(){
	while(1){
		scanf("%d %d", &c, &r);
		if(r == c && c == 0) break;
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
				scanf("%d", &sea[i][j]);
		int cnt = 0;
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++){
				if(sea[i][j] == 1){
					cnt++;
					sea[i][j] = 0;
					q.push({j, i});
					bfs();
				}
			}
		printf("%d\n", cnt);
	}
	return 0;
}
