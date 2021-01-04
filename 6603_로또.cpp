#include <stdio.h>

int k, lotto[6], arr[13];

void printLotto(int po, int cnt){
	if(cnt == 6){
		for(int i = 0; i < 6; i++){
			printf("%d ", lotto[i]);
		}
		puts("");
		return;
	}
	
	for(int i = po; i < k; i++){
		lotto[cnt] = arr[i];
		printLotto(i+1, cnt+1);
	}
	return;
}

int main(){
	while(1){
		scanf("%d", &k);
		if(k == 0) break;
		
		for(int i = 0; i < k; i++){
			scanf("%d", &arr[i]);
		}
		printLotto(0, 0);
		puts("");
	}
	return 0;
}
