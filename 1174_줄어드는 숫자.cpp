#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
vector<ll>shrink;

void getAll(ll num){
	int last = num % 10;
	for(int i = 0; i < last; i++){
		ll now = num * 10 + i;
		shrink.push_back(now);
		getAll(now);
	}
	return;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < 10; i++){
		shrink.push_back(i);
		getAll(i);
	}
	sort(shrink.begin(), shrink.end());
	
	if(n <= shrink.size()) printf("%lld", shrink[n-1]);
	else printf("-1");
	
	return 0;
}
