#include <stdio.h>

int min(int a, int b){
	return a < b ? a : b;
}

int max(int a, int b){
	return a > b ? a : b;
}

int main(){
	int n, prev_n[3], prev_x[3], next[3], mn[3] = { 0 }, mx[3] = { 0 };
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 3; j++)
			scanf("%d", &next[j]);
		
		for(int j = 0; j < 3; j++){
			prev_n[j] = mn[j];
			prev_x[j] = mx[j];
		}
		
		mx[0] = next[0] + max(prev_x[0], prev_x[1]);
		mx[2] = next[2] + max(prev_x[1], prev_x[2]);
		mx[1] = next[1] + max(max(prev_x[0], prev_x[1]), prev_x[2]);
		
		mn[0] = next[0] + min(prev_n[0], prev_n[1]);
		mn[2] = next[2] + min(prev_n[1], prev_n[2]);
		mn[1] = next[1] + min(min(prev_n[0], prev_n[1]), prev_n[2]);
	}
	
	int mxAns = 0, mnAns = 987654321;
	for(int i = 0; i < 3; i++){
		if(mxAns < mx[i]) mxAns = mx[i];
		if(mnAns > mn[i]) mnAns = mn[i];
	}
	
	printf("%d %d", mxAns, mnAns);
	
	return 0;
}
