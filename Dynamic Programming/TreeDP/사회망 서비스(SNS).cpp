// BOJ 2533 사회망 서비스(SNS) (G3)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> sns[1000001];
// dp[i][0 or 1]  = i를 root로 하는 subtree에 대해, i가 early adapter에 포함될 때 / 포함되지 않을 때
// 해당 subtree에 포함된 early adapter의 수
int dp[1000001][2];

void early_adapter(int current){
    if(dp[current][1] > 0 && dp[current][0]) 
        return;
        
    dp[current][1] = 1;
    
    for(int i=0; i<sns[current].size(); i++){
        int next = sns[current][i];
        if(dp[next][1] > 0 || dp[next][0] > 0) 
            continue;
        
        early_adapter(next);

        // 현재 노드가 early adapter => 자식 노드는 early adapter 일 수도 아닐 수도 있음
        // 따라서 최적해에 가까운(더 작은) 값 선택
        dp[current][1] += min(dp[next][1], dp[next][0]);
        // 현재 노드가 early adapter가 아님 => 자식 노드는 무조건 early adapter
        dp[current][0] += dp[next][1];
    }
}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin>>n;
    for(int i=0; i<n-1; i++){
        int u, v; cin>>u>>v;
        
        sns[u].push_back(v);
        sns[v].push_back(u);
    }
    
    for(int i=1; i<=n; i++)
        dp[i][1] = dp[i][0] = 0;
    
    early_adapter(1);

    // root 노드의 early adapter 포함 여부는 DFS 탐색 과정에서 판정되지 않으므로 출력 시 판정
    cout<<min(dp[1][1], dp[1][0])<<"\n";
    return 0;
}
