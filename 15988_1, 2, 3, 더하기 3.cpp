#include <stdio.h>

const long long DIVISION = 1000000009;

long long dp[1000001];

void get_dp(){
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for(int i = 4; i < 1000001; i++){
		dp[i] = (dp[i-3] + dp[i-2] + dp[i-1]) % (DIVISION * 10);
	}
	return;
}

int main(){
	int t;
	scanf("%d", &t);
	
	if(t) get_dp();
	
	while(t--){
		int n;
		scanf("%d", &n);
		printf("%lld\n", dp[n] % DIVISION);
	}
	
	return 0;
}
