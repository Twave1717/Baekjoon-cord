#include <stdio.h>

int gcd(int h, int l){
	if(h % l == 0) return l;
	else return gcd(l, h % l);
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int a, b;
		scanf("%d %d", &a, &b);
		int gcd_value = (a > b ? gcd(a, b) : gcd(b, a));
		printf("%d\n", gcd_value * (a / gcd_value) * (b / gcd_value));
	}
	return 0;
}
