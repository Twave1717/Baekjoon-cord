#include <stdio.h>

int main(){
	int n;
	long long ans = 0;
	scanf("%d", &n);
	for(int i = 2; i <= n; i++){
		if(i % 2 == 0)	ans = ans * 2 + 1;
		else ans = ans * 2 - 1;
		ans %= 1000000007;
	}
	printf("%lld", ans);
	return 0;
}
