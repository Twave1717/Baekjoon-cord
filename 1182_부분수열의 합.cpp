#include <stdio.h>

int n, s, cnt, seq[20];

void all(int idx, int sum){
	
	sum += seq[idx];
	
	if(idx >= n) return;
	
	if(sum == s) cnt++;
	
	all(idx + 1, sum - seq[idx]);
	all(idx + 1, sum);
		
	return;
}

int main(){
	scanf("%d %d", &n, &s);
	for(int i = 0; i < n; i++)
		scanf("%d", &seq[i]);
	
	all(0, 0);
	
	printf("%d", cnt);
	
	return 0;
}
