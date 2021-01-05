#include <stdio.h>

const int MAX = 987654321;

int dist(char a[4], char b[4]){
	int cnt = 0;
	for(int i = 0; i < 4; i++)
		if(a[i] != b[i]) cnt++;
	return cnt;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		if(n > 48){
			puts("0");
		}
		else{
			char str[48][4];
			int ans = MAX, sum;
			for(int i = 0; i < n; i++)
				scanf("%s", str[i]);
			
			for(int i = 0; i < n; i++)
				for(int j = i + 1; j < n; j++)
					for(int k = j + 1; k < n; k++){
						sum = dist(str[i], str[j]) + dist(str[j], str[k]) + dist(str[i], str[k]);
						if(ans > sum) ans = sum;
					}
			printf("%d\n", ans);
		}
	}
	return 0;
}
