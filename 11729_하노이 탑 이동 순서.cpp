#include <stdio.h>
#include <vector>
using namespace std;

vector<pair<int, int> >v;

void hanoi(int n, int from, int via, int to){
	if(n == 1) v.push_back(make_pair(from, to));
	else{
		hanoi(n-1, from, to, via);
		v.push_back(make_pair(from, to));
		hanoi(n-1, via, from, to);
	}
	return;
}

int main(){
	int n;
	scanf("%d", &n);
	hanoi(n, 1, 2, 3);
	printf("%ld\n", v.size());
	for(int i = 0; i < v.size(); i++)
		printf("%d %d\n", v[i].first, v[i].second);
	
	return 0;
}
