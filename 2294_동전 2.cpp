#include <stdio.h>

const int INF = 987654321;

int min(int a, int b){
	return a > b ? b : a;
}

int main(){
	int n, money, coin[101], dp[10001];
	scanf("%d %d", &n, &money);
	for(int i = 1; i <= n; i++) scanf("%d", &coin[i]);
	for(int i = 1; i <= money; i++) dp[i] = INF;
	dp[0] = 0;
	
	for(int i = 1; i <= n; i++){
		for(int j = coin[i]; j <= money; j++){
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}
	
	printf("%d", dp[money] == INF ? -1 : dp[money]);
	
	return 0;
}
