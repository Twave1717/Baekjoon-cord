#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char inp[9];
int w, ans, alpha[26];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s", inp);
		w = 1;
		
		for(int i = strlen(inp) - 1; i >= 0; i--, w *= 10){
			alpha[inp[i] - 'A'] += w;
		}
	}
	
	sort(alpha, alpha + 26, cmp);
	
	for(int i = 9; i >= 0; i--){
		ans += alpha[9 - i] * i;
	}
	
	printf("%d", ans);
	
	return 0;
}
