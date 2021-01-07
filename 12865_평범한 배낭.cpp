#include <stdio.h>

int n, k, mx, dp[100002], item[102][2];

int max(int a, int b){
	return a > b ? a : b;
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++){
		scanf("%d %d", &item[i][0], &item[i][1]);
	}
	for(int i = 1; i <= n; i++){
		int w = item[i][0], v = item[i][1];
		for(int j = w; j <= k; j++){
			dp[j] = max(dp[j], dp[j - w] + v);
			if(mx < dp[j]) mx = dp[j];
		}
	}
	printf("%d", mx);
	return 0;
}
