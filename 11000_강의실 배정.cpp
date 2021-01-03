#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct info{
	int t;
	int pm;
};

bool cmp(struct info a, struct info b){
	if(a.t == b.t) return a.pm < b.pm;
	return a.t < b.t;
}

int main(){
	int n;
	vector<info>time;
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int start, end;
		scanf("%d %d", &start, &end);
		time.push_back({start, 1});
		time.push_back({end, -1});
	}
	
	sort(time.begin(), time.end(), cmp);
	
	int s = time.size();
	int sum = 0, mx = 0;
	for(int i = 0; i < s; i++){
		sum += time[i].pm;
		if(mx < sum) mx = sum;
	}
	
	printf("%d", mx);
	
	return 0;
}
