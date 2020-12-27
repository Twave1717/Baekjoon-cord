#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

bool nozero[10];
char inp[13];
long long w, ans, alpha[10];

void swap(long long *a, long long *b){
	long long temp = *a;
	*a = *b;
	*b = temp;
	return;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s", inp);
		w = 1;
		
		for(int i = strlen(inp) - 1; i >= 0; i--, w *= 10){
			alpha[inp[i] - 'A'] += w;
			if(i == 0) nozero[inp[i] - 'A'] = 1;
		}
	}
	
	int z;
	for(int i = 0; i < 10; i++){
		if(!nozero[i]){
			z = i;
			break;
		}
	}
	for(int i = 0; i < 10; i++){
		if(!nozero[i] && alpha[i] < alpha[z])
			z = i;
	}
	alpha[z] = 0;
	
	sort(alpha, alpha + 10);
	
	for(int i = 0; i < 10; i++){
		ans += alpha[i] * i;
	}
	
	printf("%lld", ans);
	
	return 0;
}
