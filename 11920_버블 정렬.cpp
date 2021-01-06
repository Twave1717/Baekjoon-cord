#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;

int n, k, arr[100001];
priority_queue<int, vector<int>, greater<int> > q;

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) 
		scanf("%d", &arr[i]);
	for (int i = 0; i < k; i++)
		q.push(arr[i]);
	
	for (int i = 0; i < n - k; i++) {
		q.push(arr[i + k]);
		arr[i] = q.top();
		q.pop();
	}

	for (int i = 0; i < n-k; i++) 
		printf("%d ", arr[i]);

	while (!q.empty()) {
		printf("%d ", q.top());
		q.pop();
	}
	return 0;
}
