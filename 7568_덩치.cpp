#include <stdio.h>

int n, physical[50][2];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d %d", &physical[i][0], &physical[i][1]);
	
	for(int i = 0; i < n; i++){
		int rank = 1;
		for(int j = 0; j < n; j++){
			if(physical[i][0] < physical[j][0] && physical[i][1] < physical[j][1])
				rank++;
		}
		printf("%d ", rank);
	}
	
	return 0;
}
