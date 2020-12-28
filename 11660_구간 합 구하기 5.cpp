#include <stdio.h>

int n, m, mat[1026][1026], dp[1026][1026];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			dp[i][j] = dp[i][j-1] + dp[i-1][j] - dp[i-1][j-1] + mat[i][j];
		}
	}
	
	while(m--){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
		printf("%d\n", dp[y2][x2] - (dp[y1-1][x2] + dp[y2][x1-1] - dp[y1-1][x1-1]));
	}
	
	return 0;
}
