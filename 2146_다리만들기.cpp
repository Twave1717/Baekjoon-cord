#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

bool visit[100][100];
int map[100][100];
int n;
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
vector<pair<int, int> > v;


void fill(int a, int b, int c){

	queue<pair<int, int> >q;
	q.push(make_pair(a, b));
	visit[b][a] = 1;
	map[b][a] = c;
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
			if(visit[ny][nx] == 0 && map[ny][nx] == -1){
				visit[ny][nx] = 1;
				map[ny][nx] = c;
				q.push(make_pair(nx, ny));
			}
		}
	}
	
	return;
}

int findShort(int c){
	
	int result = 0;
	queue<pair<int, int> >q;
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(map[i][j] == c){
				q.push(make_pair(j, i));
				visit[i][j] = 1;
			}
		}
	}
	
	while(!q.empty()){
		int s = q.size();
		for(int i = 0; i < s; i++){
			
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			
			for(int j = 0; j < 4; j++){
				
				int nx = x + dx[j];
				int ny = y + dy[j];
				
				if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if(map[ny][nx] != c && map[ny][nx] != 0){
					return result;
				}
				if(map[ny][nx] == 0 && visit[ny][nx] == 0){
					visit[ny][nx] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
		result++;
	}
}

int min(int a, int b){
	return a > b ? b : a;
}

int main(){
	
	int ans = 98765431;
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 1){
				map[i][j] = -1;
				v.push_back(make_pair(i, j));
			}
		}
	}
	
	int color = 1;
	for(int i = 0; i < v.size(); i++){
		int y = v[i].first;
		int x = v[i].second;
		
		if(visit[y][x] == 0){
			fill(x, y, color++);
		}
	}
	
	
	for(int i = 1; i < color; i++){
		ans = min(ans, findShort(i));
		memset(visit, 0, sizeof(visit));
	}
	
	printf("%d", ans);
	
	return 0;
}
