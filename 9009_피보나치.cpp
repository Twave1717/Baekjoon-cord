#include <stdio.h>
#include <stack>
using namespace std;

int main(){
	int t, fibo[45] = {1, 1, };
	stack<int>s;
	for(int i = 2; i < 45; i++) fibo[i] = fibo[i-1] + fibo[i-2];
	scanf("%d", &t);
	while(t--){
		int temp;
		scanf("%d", &temp);
		for(int i = 44; temp; i--){
			if(temp >= fibo[i]){
				temp -= fibo[i];
				s.push(fibo[i]);
			}
		}
		while(!s.empty()){
			printf("%d ", s.top());
			s.pop();
		}
		puts("");
	}
	
	return 0;
}
