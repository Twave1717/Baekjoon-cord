#include <stdio.h>
#include <string.h>

int inputLen, cnt;

void luckyStr(int prev, int len, int alpha[26]){
	
	if(len == inputLen){
		cnt++;
		return;
	}
	
	for(int i = 0; i < 26; i++){
		if(alpha[i] && i != prev){
			--alpha[i];
			luckyStr(i, len + 1, alpha);
			++alpha[i];
		}
	}
	
	return;
}

int main(){
	char input[11];
	int alpha[26] = { 0 };
	
	scanf("%s", input);
	inputLen = strlen(input);
	for(int i = 0; i < inputLen; i++){
		++alpha[input[i] - 'a'];
	}
	
	for(int i = 0; i < 26; i++){
		if(alpha[i]){
			--alpha[i];
			luckyStr(i, 1, alpha);
			++alpha[i];
		}
	}
	
	printf("%d", cnt);
	
	return 0;
}
