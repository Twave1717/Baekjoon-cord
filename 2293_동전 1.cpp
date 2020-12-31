#include <stdio.h>

int main(){
	int n, money, coin[101], dp[10001] = { 0 };
	scanf("%d %d", &n, &money);
	for(int i = 1; i <= n; i++) scanf("%d", &coin[i]);
	
	dp[0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = coin[i]; j <= money; j++){
			dp[j] += dp[j - coin[i]];
		}
	}
	
	printf("%d", dp[money]);
	
	return 0;
}
