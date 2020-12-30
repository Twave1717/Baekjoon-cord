#include <stdio.h>
#include <algorithm>
using namespace std;

struct map{
	int x;
	int y;
};

bool cmp(struct map a, struct map b){
	if(a.x == b.x) return a.y < b.y;
	else return a.x < b.x;
}

int main(){
	int n;
	scanf("%d", &n);
	struct map temp[n];
	for(int i = 0; i < n; i++){
		scanf("%d %d", &temp[i].x, &temp[i].y);
	}
	
	sort(temp, temp + n, cmp);
	
	for(int i = 0; i < n; i++){
		printf("%d %d\n", temp[i].x, temp[i].y);
	}
	
	return 0;
}
