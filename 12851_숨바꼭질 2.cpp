#include <stdio.h>
#include <queue>
using namespace std;

int n, k, cnt, memo[100001];
int mn = 987654321;
queue<int>q;

void bfs(){
	
	if(n == k){
		mn = 0;
		cnt = 1;
		return;
	}
	
	q.push(n);
	
	while(!q.empty()){
		
		int now = q.front();
		q.pop();
		
		if(now - 1 >= 0 && now - 1 != n && (memo[now - 1] == memo[now] + 1 || memo[now - 1] == 0)){
			memo[now - 1] = memo[now] + 1;
			if(memo[now - 1] <= mn) q.push(now - 1);
			if(now - 1 == k){
				mn = memo[now - 1];
				cnt++;
			}
		}
		if(now + 1 <= 100000 && (memo[now + 1] == memo[now] + 1 || memo[now + 1] == 0)){
			memo[now + 1] = memo[now] + 1;
			if(memo[now + 1] <= mn) q.push(now + 1);
			if(now + 1 == k){
				mn = memo[now + 1];
				cnt++;
			}
		}
		if(now * 2 <= 100000 && (memo[now * 2] == memo[now] + 1 || memo[now * 2] == 0)){
			memo[now * 2] = memo[now] + 1;
			if(memo[now * 2] <= mn) q.push(now * 2);
			if(now * 2 == k){
				mn = memo[now * 2];
				cnt++;
			}
		}
	}
	return;
}

int main(){
	scanf("%d %d", &n, &k);
	bfs();
	printf("%d\n%d", mn, cnt);
	return 0;
}
