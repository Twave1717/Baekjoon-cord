#include <stdio.h>

int g, p, cnt, parent[100001];

int find(int x){
	if(x == parent[x])
		return x;
	else
		return parent[x] = find(parent[x]);
}

void unite(int x, int y){
	x = find(x);
	y = find(y);
	parent[x] = y;
	return;
}

int main(){
	scanf("%d\n%d", &g, &p);
	for(int i = 1; i <= g; i++){
		parent[i] = i;
	}
	for(int i = 0; i < p; i++){
		int temp;
		scanf("%d", &temp);
		int empty_gate = find(temp);
		if(empty_gate == 0){
			break;
		}
		else{
			cnt++;
			unite(empty_gate, empty_gate - 1);
		}
	}
	
	for(int i = 1; i <= g; i++){
		printf("%d: %d\n", i, parent[i]);
	}
	
//	printf("%d", cnt);
	return 0;
}
