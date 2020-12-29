#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int n, k, memo[100001], link[100001];
queue<int>q;
vector<int>v;

int bfs(){
	
	if(n == k) return 0;
	
	q.push(n);
	
	while(!q.empty()){
		
		int now = q.front();
		q.pop();
		
		if(now - 1 >= 0 && now - 1 != n && memo[now - 1] == 0){
			memo[now - 1] = memo[now] + 1;
			link[now - 1] = now;
			q.push(now - 1);
			if(now - 1 == k){
				return memo[now - 1];
			}
		}
		if(now + 1 <= 100000 && memo[now + 1] == 0){
			memo[now + 1] = memo[now] + 1;
			link[now + 1] = now;
			q.push(now + 1);
			if(now + 1 == k){
				return memo[now + 1];
			}
		}
		if(now * 2 <= 100000 && memo[now * 2] == 0){
			memo[now * 2] = memo[now] + 1;
			link[now * 2] = now;
			q.push(now * 2);
			if(now * 2 == k){
				return memo[now * 2];
			}
		}
	}
}

int main(){
	scanf("%d %d", &n, &k);
	printf("%d\n", bfs());
	
	v.push_back(k);
	for(int i = k; i != n; i = link[i]){
		v.push_back(link[i]);
	}
	for(int i = v.size() - 1; i >= 0; i--){
		printf("%d ", v[i]);
	}
	return 0;
}
