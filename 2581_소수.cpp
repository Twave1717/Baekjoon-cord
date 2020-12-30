#include <stdio.h>

bool primeCheck[10001];

void getPrime(){
	for(int i = 2; i <= 100; i++){
		if(!primeCheck[i]){
			for(int j = 2; i * j <= 10000; j++){
				primeCheck[i * j] = 1;
			}
		}
	}
	return;
}

int main(){
	int from, to, sum = 0, mn = 0;
	scanf("%d\n%d", &from, &to);
	primeCheck[0] = primeCheck[1] = true;
	getPrime();
	for(int i = from; i <= to; i++){
		if(!primeCheck[i]){
			sum += i;
			if(mn == 0) mn = i;
		}
	}
	
	if(mn != 0) printf("%d\n%d", sum, mn);
	else printf("-1");
	
	return 0;
}
