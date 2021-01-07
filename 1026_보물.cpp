#include <stdio.h>
#include <algorithm>
using namespace std;

int n, sum, a[50], b[50];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	sort(a, a + n, cmp);
	sort(b, b + n);
	for(int i = 0; i < n; i++)
		sum += a[i] * b[i];
	printf("%d", sum);
	return 0;
}
