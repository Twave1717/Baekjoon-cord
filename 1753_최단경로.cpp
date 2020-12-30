#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;

const int INF = 987654321;

int v, e, start, dist[20001];
vector<pair<int, int> >link[20001];

void dijkstra(){
	dist[start] = 0;
	
	priority_queue<pair<int, int> >pq;
	pq.push(make_pair(0, start));
	
	while(!pq.empty()){
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		
		if(dist[now] < cost) continue;
		
		for(int i = 0; i < link[now].size(); i++){
			int next = link[now][i].second;
			int nextDist = cost + link[now][i].first;
			
			if(dist[next] > nextDist){
				dist[next] = nextDist;
				pq.push(make_pair(-nextDist, next));
			}
		}
	}
	
	return;
}

int main(){
	scanf("%d %d\n%d", &v, &e, &start);
	for(int i = 0; i < e; i++){
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		link[from].push_back(make_pair(cost, to));
	}
	
	for(int i = 1; i <= v; i++) dist[i] = INF;
	
	dijkstra();
	
	for(int i = 1; i <= v; i++){
		if(dist[i] == INF) puts("INF");
		else printf("%d\n", dist[i]);
	}
	
	return 0;
}
