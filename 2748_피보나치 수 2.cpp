#include <stdio.h>

int n;
long long memo[100] = {0, 1};

long long solve(int step){
	
	memo[step] = memo[step-1] + memo[step-2];
	
	if (step >= n) return memo[n];
	else return solve(step + 1);
}

int main(){
	
	scanf("%d", &n);
	printf("%lld", solve(2));
	
	return 0;
}
