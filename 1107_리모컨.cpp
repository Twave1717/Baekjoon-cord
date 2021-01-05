#include <stdio.h>
#include <vector>
using namespace std;

const int MAX = 987654321;

bool brk[10];
int goal, ans = MAX;

int gap(int a, int b){
	if(a > b) return a - b;
	else return b - a;
}

int min(int a, int b){
	return a < b ? a : b;
}

void getAll(int len, int sum){
	
	if(len > 6) return;
	
	int temp;
	for(int i = 0; i < 10; i++){
		if(!brk[i]){
			temp = (sum * 10) + i;
			ans = min(gap(goal, temp) + len, ans);
			getAll(len + 1, temp);
		}
	}
	return;
}

int main(){
	int temp1, temp2;
	scanf("%d\n%d", &goal, &temp1);
	for(int i = 0; i < temp1; i++){
		scanf("%d", &temp2);
		brk[temp2] = 1;
	}
	
	getAll(1, 0);
	
	ans = min(gap(100, goal), ans);
	
	printf("%d", ans);
	
	return 0;
}
