#include <stdio.h>

char inp[100001];
int sum, pole;

int main(){
	scanf("%s", inp);
	for(int i = 0; inp[i] != '\0'; i++){
		if(inp[i] == '(' && inp[i+1] == ')'){
			sum += pole;
			i++;
		}
		else if(inp[i] == '('){
			sum++;
			pole++;
		}
		else{
			pole--;
		}
	}
	printf("%d", sum);
	return 0;
}
