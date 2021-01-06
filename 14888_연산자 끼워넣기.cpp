#include <stdio.h>

const int MAX = 1000000001;
const int MIN = -1000000001;

int n, oper[4], num[11], mx = MIN, mn = MAX;

void input(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &num[i]);
	for(int i = 0; i < 4; i++)
		scanf("%d", &oper[i]);
	return;
}

void bruteForce(int len, int sum){
	if(len == n){
		if(mx < sum) mx = sum;
		if(mn > sum) mn = sum;
		return;
	}
	for(int i = 0; i < 4; i++){
		if(oper[i] > 0){
			oper[i]--;
			if(i == 0)
				bruteForce(len+1, sum + num[len]);
			if(i == 1)
				bruteForce(len+1, sum - num[len]);
			if(i == 2)
				bruteForce(len+1, sum * num[len]);
			if(i == 3)
				bruteForce(len+1, sum / num[len]);
			oper[i]++;
		}
	}
	return;
}

int main(){
	input();
	bruteForce(1, num[0]);
	printf("%d\n%d", mx, mn);
	
	return 0;
}
