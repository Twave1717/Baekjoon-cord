#include <stdio.h>

int main(){
	int n, memo[1002] = { 0 };	scanf("%d", &n);
	int temp;
	for(int i = 0; i < n; i++){
		scanf("%d", &temp);
		memo[temp]++;
	}
	
	for(int i = 0; i < 1002; i++){
		if(memo[i] > 0){
			
			if(memo[i+1] == 0){
				while(memo[i]--){
					printf("%d ", i);
				}
			}
			
			else{
				int j = 2 - 1;
				while(j++){
					
					if(memo[i + j] > 0){
						
						while(memo[i]--){
							printf("%d ", i);
						}
						
						printf("%d ", i + j);
						memo[i + j]--;
						
						break;
					}
					
					if(i + j > 1000){
						
						while(memo[i+1]--){
							printf("%d ", i+1);
						}
						while(memo[i]--){
							printf("%d ", i);
						}
						
						break;
					}
				}
			}
		}
	}
	
	return 0;
}

