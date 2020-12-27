#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

bool visit[1001];
int n, m, cnt;
vector<int>v[1001];
queue<int>q;

void bfs(){
	while(!q.empty()){
		int now = q.front();
		int s = v[now].size();
		q.pop();
		
		for(int i = 0; i < s; i++){
			if(visit[v[now][i]] == 0){
				visit[v[now][i]] = 1;
				cnt--;
				q.push(v[now][i]);
			}
		}
	}
	return;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	for(int i = 1; i <= n; i++){
		if(visit[i] == 0 && !v[i].empty()){
			visit[i] = 1;
			q.push(i);
			bfs();
		}
		cnt++;
	}
	
	printf("%d", cnt);
	
	return 0;
}
