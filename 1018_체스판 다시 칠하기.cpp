#include <stdio.h>

int w, h;
bool chess[100][100];

int try_slice_case(int start_h, int start_w){
	
	bool tries[2] = {0, 1};
	int case_ans = 100000007;
	
		
	for(int n = 0; n < 2; n++){
		int cnt = 0;
		for(int i = start_h; i < start_h+8; i++){
			for(int j = start_w; j < start_w+8; j++){
				
				if(chess[i][j] != tries[n]) cnt++;
				tries[n] = !tries[n];
				
			}
			tries[n] = !tries[n];
			
		}
		if(case_ans > cnt) case_ans = cnt;
	}
	
	
	return case_ans;
}

void input(){
	scanf("%d %d", &h, &w);
	char inp[h][w];
	for(int i = 0; i < h; i++){
		scanf("%s", &inp[i]);
		for(int j = 0; j < w; j++){
			if(inp[i][j] == 'W') chess[i][j] = 1; //White = 1, Black = 0
			else chess[i][j] = 0;
		}
	}
	
	int ans = 100000007;
	for(int i = 0; i < h - 7; i++){
		int temp;
		for(int j = 0; j < w - 7; j++){
			temp = try_slice_case(i, j);
			if(ans > temp) ans = temp;
		}
	}
	
	printf("%d", ans);
	
	
	return;
}

int main(){
	
	input();
	
	
	
	
}
