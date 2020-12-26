#include <stdio.h>

char from, to;
int n, m;
bool prm[26][26];

void floyd(){
	for(int k = 0; k < 26; k++)
		for(int i = 0; i < 26; i++)
			for(int j = 0; j < 26; j++)
				if((prm[i][k] == 1) && (prm[k][j] == 1)) prm[i][j] = 1;
	
	return;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("\n%c is %c", &from, &to);
		prm[from - 'a'][to - 'a'] = 1;
	}
	
	floyd();
	
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("\n%c is %c", &from, &to);
		printf("%c\n", prm[from - 'a'][to - 'a'] == 1 ? 'T' : 'F');
	}
	return 0;
}
