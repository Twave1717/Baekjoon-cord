#include <stdio.h>
#include <queue>
using namespace std;

int n, k, memo[100001];
queue<int>q;

int bfs(){
	
	if(n == k) return 0;
	
	q.push(n);
	
	while(!q.empty()){
		
		int now = q.front();
		q.pop();
		
		if(now - 1 >= 0 && now - 1 != n && memo[now - 1] == 0){
			memo[now - 1] = memo[now] + 1;
			q.push(now - 1);
			if(now - 1 == k){
				return memo[now - 1];
			}
		}
		if(now + 1 <= 100000 && memo[now + 1] == 0){
			memo[now + 1] = memo[now] + 1;
			q.push(now + 1);
			if(now + 1 == k){
				return memo[now + 1];
			}
		}
		if(now * 2 <= 100000 && memo[now * 2] == 0){
			memo[now * 2] = memo[now] + 1;
			q.push(now * 2);
			if(now * 2 == k){
				return memo[now * 2];
			}
		}
	}
}

int main(){
	scanf("%d %d", &n, &k);
	printf("%d", bfs());
	return 0;
}
