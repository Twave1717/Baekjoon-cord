#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
	int n, seq[10000], flag = 1, sum = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &seq[i]);
	}
	
	sort(seq, seq + n);
	
	for(int i = 1; i <= n; i++){
		sum += seq[i-1];
		if(i * (i - 1) / 2 > sum){
			flag = -1;
			break;
		}
	}
	if(n * (n-1) / 2 != sum) flag = -1;
	
	printf("%d", flag);
	
	return 0;
}
