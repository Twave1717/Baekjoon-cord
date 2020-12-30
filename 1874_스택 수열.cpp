#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;

int n, idx, goal, arr[100000];
vector<char>v;
stack<int>s;

int main(){
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)	scanf("%d", &arr[i]);
	
	for(int i = 1; i <= n; i++){
		s.push(i);
		v.push_back('+');
		
		while(!s.empty() && s.top() == arr[idx]){
			s.pop();
			v.push_back('-');
			idx++;
		}
	}
	
	if(!s.empty()) puts("NO");
	else{
		for(int i = 0; i < v.size(); i++){
			printf("%c\n", v[i]);
		}
	}
	
	return 0;
}
