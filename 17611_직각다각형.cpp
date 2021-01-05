#include <stdio.h>
#include <algorithm>
#include <string.h>
#define M 500000
#define N 1000001
using namespace std;

int n, dot[N], e[100000][2];
int i, j, k, s, t;

int main(){
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d %d", &e[i][0], &e[i][1]);
	for(j = 0; j < 2; j++){
		memset(dot, 0, sizeof(dot));
		for(i = j; i < n; i += 2){
			k = (i + 1) % n;
			if(e[i][0] != e[k][0]){
				dot[min(e[i][0], e[k][0]) + M]++;
				dot[max(e[i][0], e[k][0]) + M]--;
			}
			else{
				dot[min(e[i][1], e[k][1]) + M]++;
				dot[max(e[i][1], e[k][1]) + M]--;
			}
		}
		for(t=k=i=0; i < N; i++){
			k += dot[i];
			t = max(t, k);
		}
		s = max(s, t);
	}
	printf("%d", s);
	
	return 0;
}
//https://lastknight00.tistory.com/103
