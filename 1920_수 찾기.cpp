#include <stdio.h>
#include <algorithm>
using namespace std;


int main(){
	
	int n, m, base[100001];

	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &base[i]);
	
	for(int i = 0; i < m; i++){
		scanf("%d", &base[i]);
	}
	sort(base, base + n);
	
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int search, mid, start = 0, end = n-1;
		scanf("%d", &search);
		
		while(start <= end){
			mid = (start + end) / 2;
			if(search == base[mid]){
				puts("1");
				break;
			}
			else if(search < base[mid]){
				end = mid - 1;
			}
			else{
				start = mid + 1;
			}
		}
		
		if(start > end) puts("0");
	}
	
	return 0;
}
