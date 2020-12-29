#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

int n, k, memo[100001], mn = 987654321;
queue<int>q;

void bfs(){
	
	if(n == k){
		mn = 0;
		return;
	}
	
	memo[n] = 0;
	q.push(n);
	
	while(!q.empty()){
		
		int now = q.front();
		q.pop();
		
		if(now - 1 >= 0 && now - 1 != n && (memo[now - 1] == -1 || memo[now - 1] > memo[now] + 1)){
			memo[now - 1] = memo[now] + 1;
			q.push(now - 1);
			if(now - 1 == k){
				mn = memo[now - 1];
			}
		}
		if(now + 1 <= 100000 && (memo[now + 1] == -1 || memo[now + 1] > memo[now] + 1)){
			memo[now + 1] = memo[now] + 1;
			q.push(now + 1);
			if(now + 1 == k){
				mn = memo[now + 1];
			}
		}
		if(now * 2 <= 100000 && (memo[now * 2] == -1 || memo[now * 2] > memo[now])){
			memo[now * 2] = memo[now];
			q.push(now * 2);
			if(now * 2 == k){
				mn = memo[now * 2];
			}
		}
	}
	return;
}

int main(){
	scanf("%d %d", &n, &k);
	memset(memo, -1, sizeof(memo));
	bfs();
	printf("%d", mn);
	return 0;
}
