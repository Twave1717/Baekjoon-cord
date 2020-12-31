#include <stdio.h>
#include <math.h>

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		long long a, b, c;
		scanf("%lld %lld", &a, &b);
		c = (int)sqrt(b - a);
		
		if(c*c == b-a) printf("%lld\n", 2 * c - 1);
		else if(c*c < b-a && b-a <= c*c+c) printf("%lld\n", 2 * c);
		else if(c*c+c < b-a && b-a < (c+1)*(c+1)) printf("%lld\n", 2 * c + 1);
	}
	return 0;
}
