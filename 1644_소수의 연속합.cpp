#include <stdio.h>
#include <vector>
using namespace std;

int n, last_i, sum, cnt;
bool primeCheck[4000001] = {1, 1, };
vector<int>prime;

void getPrime(){
	for(int i = 2; i <= n; i++){
		if(!primeCheck[i]){
			prime.push_back(i);
			for(int j = 2; j * i <= n; j++){
				primeCheck[j * i] = 1;
			}
		}
	}
	return;
}

int main(){
	scanf("%d", &n);
	getPrime();	
	
	int s = prime.size();
	for(int i = 0; i < s && prime[i] <= n; i++){
		sum += prime[i];
		
		while(sum > n){
			sum -= prime[last_i++];
			}
		
		if(sum == n) cnt++;
	}
	
	printf("%d", cnt);
	
	return 0;
}
