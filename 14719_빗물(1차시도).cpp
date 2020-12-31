#include <stdio.h>

bool pool, map[500][501];
int h, wid, cnt, sum;

int main(){
	scanf("%d %d", &h, &wid);
	for(int i = 0; i < wid; i++){
		int temp;
		scanf("%d", &temp);
		for(int j = 0; j < temp; j++){
			map[j][i] = 1;
		}
	}
	
	for(int i = 0; i < h; i++){
		cnt = 0;
		pool = 0;
		for(int j = 0; j < wid; j++){
			if(pool){
				cnt++;
//				printf("\n%d %d", i, j);
			}
			if(map[i][j]){
				if(pool == 1){
					pool = 0;
					sum += cnt - 1;
					cnt = 0;
				}
				if(pool == 0 && map[i][j+1] == 0) pool = 1;
			}
		}
	}
	
//	for(int i = 0; i < h; i++){
//		puts("");
//		for(int j = 0; j < wid; j++)
//			printf("%d ", map[i][j] ? 1 : 0);
//	}
	
	printf("%d", sum);
	
	return 0;
}
