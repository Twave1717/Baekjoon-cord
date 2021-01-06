#include <stdio.h>
#include <queue>
using namespace std;

struct loc{
	int x;
	int y;
};

bool map[100][100], air[100][100];
int r, c, cheese_amt;
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
queue<loc>q, airLink;

void getAir(){
	airLink.push({0, 0});
	air[0][0] = 1;
	
	while(!airLink.empty()){
		int x = airLink.front().x;
		int y = airLink.front().y;
		airLink.pop();
		
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
			if(!map[ny][nx] && !air[ny][nx]){
				air[ny][nx] = 1;
				airLink.push({nx, ny});
			}
		}
	}
	return;
}

bool melt(int x, int y){
	bool contact = 0;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(air[ny][nx]){
			contact = 1;
			break;
		}
	}
	return contact;
}

void getAns(){
	
	int time = 0;
	
	while(!q.empty()){
		
		time++;
		int meltedCheese = 0;
		int s = q.size();
		
		for(int i = 0; i < s; i++){
			int x = q.front().x;
			int y = q.front().y;
			q.pop();
			
			if(melt(x, y)){
				airLink.push({x, y});
				meltedCheese++;
			}
			else{
				q.push({x, y});
			}
		}
		
		if(cheese_amt - meltedCheese > 0) cheese_amt -= meltedCheese;
		
		while(!airLink.empty()){
			int x = airLink.front().x;
			int y = airLink.front().y;
			airLink.pop();
			
			air[y][x] = 1;
			map[y][x] = 0;
			
			for(int i = 0; i < 4; i++){
				int nx = x + dx[i];
				int ny = y + dy[i];
				if(!map[ny][nx] && !air[ny][nx]){
					air[ny][nx] = 1;
					airLink.push({nx, ny});
				}
			}
		}
	}
	
	printf("%d\n%d", time, cheese_amt);
	
	return;
}

int main(){
	scanf("%d %d", &r, &c);
	int temp;
	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++){
			scanf("%d", &temp);
			map[i][j] = (temp == 1 ? 1 : 0);
			if(temp == 1){
				cheese_amt++;
				q.push({j, i});
			}
		}
	
	getAir();
	getAns();
	
	return 0;
}
