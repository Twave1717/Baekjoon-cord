#include<stdio.h>

int c[31][31];

void get_dp(){
	for(int i = 1; i < 31; i++){
		c[i][i] = 1;
		c[i][1] = i;
	}
	for(int i = 2; i < 31; i++){
		for(int j = 2; j < 31; j++){
			if(i>j)
				c[i][j] = c[i-1][j-1] + c[i-1][j];		}
	}
}

int main(){
	int t;
	scanf("%d", &t);
	
	get_dp();
	
	while(t--){
		int n, m;
		scanf("%d %d", &n, &m);
		printf("%d\n", c[m][n]);
	}
	return 0;
}
