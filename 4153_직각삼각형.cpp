#include <stdio.h>

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

char* check_pita(int inp[]){
	if(inp[0] * inp[0] == inp[1] * inp[1] + inp[2] * inp[2]) {
		static char ret[50] = "right";
		return ret;	
	}
	else{
		static char ret[50] = "wrong";
		return ret;	
	}
}

int main(){
	while(true){
		int inp[3];
		for(int i = 0; i < 3; i++){
			scanf("%d", &inp[i]);
		}
		
		if(inp[0] == 0) break;
		
		for(int i = 0; i < 3; i++){
			for(int j = i; j < 3; j++){
				if(inp[j] > inp[i])
				swap(&inp[j], &inp[i]);
			}
		}
		
		printf("%s\n", check_pita(inp));
	}
	
	return 0;
}
