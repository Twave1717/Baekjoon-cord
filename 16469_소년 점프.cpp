#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
int r, c, dp[101][101];
bool visit[101][101][3];
char map[101][101];
queue<pair<int, int> >q;

void bfs(int x, int y, int mode){
	
	q.push(make_pair(x, y));
	
	int dist = 0;
	while(!q.empty()){
		int s = q.size();
		dist++;
		
		for(int i = 0; i < s; i++){
			x = q.front().first;
			y = q.front().second;
			q.pop();
			
			for(int j = 0; j < 4; j++){
				
				int nx = x + dx[j];
				int ny = y + dy[j];
				
				if(nx < 1 || ny < 1 || nx > c || ny > r) continue;
				if(map[ny][nx] == '0' && visit[ny][nx][mode] == 0){
					if(dp[ny][nx] < dist) dp[ny][nx] = dist;
					visit[ny][nx][mode] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return;
}

int main(){
	scanf("%d %d", &r, &c);
	char temp[c];
	for(int i = 1; i <= r; i++){
		scanf("%s", map[i] + 1);
	}
	
	for(int i = 0; i < 3; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		visit[a][b][i] = 1;
		bfs(b, a, i); 
	}
	
	int min = 987654321, cnt = 0;
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			if(dp[i][j] > 0 && min > dp[i][j] && (visit[i][j][0] && visit[i][j][1] && visit[i][j][2])){
				min = dp[i][j];
				cnt = 0;
			}
			if(min == dp[i][j]){
				cnt++;
			}
		}
	}
	
	if(min == 987654321) printf("-1");
	else printf("%d\n%d", min, cnt);
	
	return 0;
}
