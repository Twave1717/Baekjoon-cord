#include <stdio.h>

const int LIM = 987654321;

int n, s, len, sum, last_i, seq[100000], ans = LIM;

int main(){
	scanf("%d %d", &n, &s);
	for(int i = 0; i < n; i++){
		scanf("%d", &seq[i]);
		sum += seq[i];
		len++;
		
		while(sum - seq[last_i] >= s){
			sum -= seq[last_i++];
			len--;
		}
		
		if(sum >= s && len < ans){
			ans = len;
		}
	}
	printf("%d", ans == LIM ? 0 : ans);
	
	return 0;
}
