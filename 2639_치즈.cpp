#include <stdio.h>
#include <queue>
using namespace std;

const int MAX = 100;

struct location{
	int x;
	int y;
};

bool map[MAX][MAX], air[MAX][MAX], temp[MAX][MAX];
int r, c;
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
queue<location>q, airLink;

void getAir(){
	
	queue<location>qq;
	qq.push({0, 0});
	
	while(!qq.empty()){
		int x = qq.front().x;
		int y = qq.front().y;
		qq.pop();
		
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
			if(map[ny][nx] == 0 && air[ny][nx] == 0){
				temp[ny][nx] = air[ny][nx] = 1;
				qq.push({nx, ny});
			}
		}
	}
	return;
}

bool melt(int x, int y){
	int cnt = 0;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(air[ny][nx]) cnt++;
	}
	
	return cnt >= 2 ? 1 : 0;
}

int getAns(){
	
	int hour = 0;
	while(!q.empty()){
		hour++;
		int s = q.size();
		for(int k = 0; k < s; k++){
			int x = q.front().x;
			int y = q.front().y;
			q.pop();
			
			if(melt(x, y)){
				map[y][x] = 0;
				airLink.push({x, y});
			}
			else{
				q.push({x, y});
			}
		}
		
		while(!airLink.empty()){
			int x = airLink.front().x;
			int y = airLink.front().y;
			airLink.pop();
			
			air[y][x] = 1;
			
			for(int i = 0; i < 4; i++){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
				if(map[ny][nx] == 0 && !air[ny][nx]){
					air[ny][nx] = 1;
					airLink.push({nx, ny});
				}
			}
		}
	}
	
	return hour;
}

int main(){
	scanf("%d %d", &r, &c);
	int temp;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			scanf("%d", &temp);
			map[i][j] = temp == 1 ? 1 : 0;
			
			if(map[i][j] == 1){
				q.push({j, i});
			}
		}
	}
	
	getAir();
	printf("%d", getAns());
	
	return 0;
} 
