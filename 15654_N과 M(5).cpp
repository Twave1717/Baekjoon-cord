#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m, inp[9], seq[9];
bool visit[9];

void solve(int cnt){
	
	if(cnt == m){
		for(int i = 0; i < m; i++){
			printf("%d ", seq[i]);
		}
		puts("");
		return;
	}
	
	for(int i = 0; i < n; i++){
		if(!visit[i]){
			visit[i] = 1;
			seq[cnt] = inp[i];
			solve(cnt+1);
			visit[i] = 0;
		}
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%d", &inp[i]);
	sort(inp, inp + n);
	
	solve(0);
	return 0;
}
