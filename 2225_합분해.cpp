#include <stdio.h>
const int LIMIT = 1000000000;

int n, k, dp[201][201];

int main(){
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i <= n; i++){
		dp[1][i] = dp[i][0] = 1;
	}
	for(int i = 2; i <= k; i++){
		long long sum = 0;
		for(int j = 0; j <= n; j++){
			sum = (sum + dp[i-1][j]) % LIMIT;
			dp[i][j] = sum;
		}
	}
	
	printf("%d", dp[k][n]);
	
	return 0;
}
