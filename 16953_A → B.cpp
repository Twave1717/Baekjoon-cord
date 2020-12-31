#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
typedef long long ll;

int bfs(int n, int goal){
	queue<pair<ll, ll> >q; // first => ¼ö, second => ¿¬»êÈ½¼ö
	q.push(make_pair(n, 1));
	
	while(!q.empty()){
		ll now = q.front().first;
		ll cnt = q.front().second;
		q.pop();
		
		if(now == goal) return cnt;
		
		if(now * 2 <= goal){
			q.push(make_pair(now * 2, cnt + 1));
		}
		if(now * 10 + 1 <= goal){
			q.push(make_pair(now * 10 + 1, cnt + 1));
		}
	}
	
	return -1;
}

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", bfs(a, b));
	return 0;
}
