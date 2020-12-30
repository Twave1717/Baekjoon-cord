#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

const int cityMax = 1000 + 1;
const int busMax = 100000 + 1;
const int INF = 987654321;

int n, m, start, goal;
vector<pair<int, int> >v[cityMax];

int dijkstra(){
	vector<int>dist(n + 1, INF);
	dist[start] = 0;
	
	priority_queue<pair<int, int> >pq;
	pq.push(make_pair(0, start));
	
	while(!pq.empty()){
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		
		if(dist[now] < cost) continue;
		
		for(int i = 0; i < v[now].size(); i++){
			int next = v[now][i].second;
			int nextDist = cost + v[now][i].first;
			
			if(dist[next] > nextDist){
				dist[next] = nextDist;
				pq.push(make_pair(-nextDist, next));
			}
		}
	}
	
	return dist[goal];
}

int main(){
	scanf("%d\n%d", &n, &m);
	for(int i = 0; i < m; i++){
		int from, to, cost;
		scanf("%d %d %d", &from, &to, &cost);
		v[from].push_back(make_pair(cost, to));
	}
	scanf("%d %d", &start, &goal);
	
	printf("%d", dijkstra());
	
	return 0;
}
