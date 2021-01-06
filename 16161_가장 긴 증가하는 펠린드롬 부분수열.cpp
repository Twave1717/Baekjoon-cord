#include <stdio.h>

int n, len, w, k, seq[100000], mx = 1;

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &seq[i]);
	
	for(int i = 0; i + 1 < n; i++){
		
		if(seq[i] < seq[i+1]) continue;
		
		else{
			if(seq[i] == seq[i+1]) len = 2, w = 1;
			else len = 1, w = 0;
			
			k = 1;
			while(i-k >= 0 && i+k+w < n && seq[i-k] == seq[i+k+w] && seq[i+k+w-1] > seq[i+k+w]){
				len += 2;
				k++;
			}
			
			if(len > mx) mx = len;
			
			while(i + k + 1 < n && seq[i + k] < seq[i + k + 1]) i++;
		}
	}
	
	printf("%d", mx);
	
	return 0;
}
