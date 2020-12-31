#include <stdio.h>

int h, wid, ans, map[500];

int min(int a, int b){
	return a < b ? a : b;
}

int max(int a, int b){
	return a > b ? a : b;
}

int main(){
	scanf("%d %d", &h, &wid);
	for(int i = 0; i < wid; i++) scanf("%d", &map[i]);
	
	int left, right;
	for(int i = 1; i < wid - 1; i++){
		left = right = 0;
		for(int j = 0; j < i; j++) if(left < map[j]) left = map[j];
		for(int j = wid - 1; j > i; j--) if(right < map[j]) right = map[j];
		ans += max(0, min(left, right) - map[i]);
	}
	printf("%d", ans);
	return 0;
}
