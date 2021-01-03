#include <stdio.h>

int main(){
	int k, d, a;
	scanf("%d/%d/%d", &k, &d, &a);
	if(k + a < d || d == 0) puts("hasu");
	else puts("gosu");
	return 0;
}
