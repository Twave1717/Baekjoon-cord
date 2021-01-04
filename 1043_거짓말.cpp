#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 50 + 1;

vector<int>relatedParties[MAX];
bool revealed[MAX];
bool participatedParty[MAX][MAX];
bool revealedParty[MAX];


int main(){
	
	int n, m;
	scanf("%d %d", &n, &m);
	
	int truth;
	scanf("%d", &truth);
	
	for(int i = 0; i < truth; i++){
		int idx;
		scanf("%d", &idx);
		
		revealed[idx] = 1;
	}
	
	queue<int>q;
	
	for(int i = 0; i < m; i++){
		
		int num;
		scanf("%d", &num);
		
		for(int j = 0; j < num; j++){
			
			int idx;
			scanf("%d", &idx);
			
			participatedParty[i][idx] = 1;
			
			if(revealed[idx] && !revealedParty[i]){
				
				revealedParty[i] = 1;
				
				q.push(i);
			}
			
			for(int k = 0; k < i; k++){
				
				bool hasParticipated = participatedParty[k][idx];
				
				if(hasParticipated){
					relatedParties[k].push_back(i);
					relatedParties[i].push_back(k);
				}
			}
		}
	}
	
	while(!q.empty()){
		int partyIdx = q.front();
		q.pop();
		
		for(int i = 0; i < relatedParties[partyIdx].size(); i++){
			
			int party = relatedParties[partyIdx][i];
			
			if(revealedParty[party] == 0){
				
				revealedParty[party] = true;
				
				q.push(party);
			}
		}
	}
	
	int ans = 0;
	
	for(int i = 0; i < m; i++){
		if(revealedParty[i] == 0){
			ans++;
		}
	}
	
	printf("%d", ans);
	
	return 0;
}
