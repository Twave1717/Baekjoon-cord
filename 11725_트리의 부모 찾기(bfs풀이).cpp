#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int n, parent[100001];
vector<int>link[100001];
queue<int>q;

void bfs(){
	
	while(!q.empty()){
		int now = q.front();
		int s = link[now].size();
		q.pop();
		
		for(int i = 0; i < s; i++){
			if(parent[link[now][i]] == 0){
				parent[link[now][i]] = now;
				q.push(link[now][i]);
			}
		}
	}
	
	return;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		link[a].push_back(b);
		link[b].push_back(a);
	}
	
	parent[1] = -1;
	q.push(1);
	bfs();
	
	for(int i = 2; i <= n; i++){
		printf("%d\n", parent[i]);
	}
	
	return 0;
}
