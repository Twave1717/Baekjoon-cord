#include <stdio.h>
const int INF = 987654321;

int n, m, cost[101][101];

int min(int a, int b){
	return a > b ? b : a;
}

void floyd_warshall(){
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			for(int k = 1; k <= n; k++){
				if(cost[j][i] != INF && cost[i][k] != INF){
					cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k]);
				}
			}
		}
	}
	return;
}

int main(){
	scanf("%d\n%d", &n, &m);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cost[i][j] = INF;
		}
	}
	
	int a, b, c;
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &a, &b, &c);
		if(cost[a][b] > c){
			cost[a][b] = c;
		}
	}
	
	floyd_warshall();
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d ", (cost[i][j] == INF) || (i == j) ? 0 : cost[i][j]);
		}
		puts("");
	}
	
	return 0;
}
