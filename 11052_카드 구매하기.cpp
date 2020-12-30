#include <stdio.h>

int n, cost[1001], dp[1001];

int big(int a, int b){
	return a > b ? a : b;
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &cost[i]);
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			dp[i] = big(dp[i], dp[i-j] + cost[j]);
		}
	}
	
	printf("%d", dp[n]);
	
	return 0;
}
