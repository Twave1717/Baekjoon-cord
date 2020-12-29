#include <stdio.h>
#include <vector>
using namespace std;

// 1. ��Ʈ ��尡 �������� ���.
// 2. ���� ������尡 �ƴϾ��µ� �ڽĳ�尡 �� �������� ���� ������尡 �� ���.

int n, start, leaf;
bool elm[51];
vector<int>child[51];

void dfs(int now){
	elm[now] = 1;
	for(int i = child[now].size() - 1; i >= 0; i--){
		dfs(child[now][i]);
	}
	return;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int temp;
		scanf("%d", &temp);
		if(temp == -1) continue;
		
		child[temp].push_back(i);
	}
	scanf("%d", &start);
	dfs(start);
	
	for(int i = 0; i < n; i++){
		if(child[i].empty() && !elm[i]) leaf++;
		else if(!elm[i]){
			for(int j = child[i].size() - 1; j >= 0; j--){
				if(!elm[child[i][j]]) break;
				if(j == 0) leaf++;
			}
		}
	}
	
	printf("%d", leaf);
	
	return 0;
}
