#include <stdio.h>
#include <vector>
using namespace std;

const int MOD = 10007;

int ans, sum, n, dp[11][1000];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < 10; i++){
		dp[i][0] = 1;
		sum = dp[i][0];
		ans += sum;
	}
	for(int i = 1; i < n; i++){
		sum = 0, ans = 0;
		for(int j = 0; j < 10; j++){
			sum += dp[j][i-1];
			ans += sum;
			dp[j][i] = sum % MOD;
		}
	}
	printf("%d", ans);
	return 0;
}
