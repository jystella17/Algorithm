// BOJ 14728 벼락치기 (G5)
// 0-1 Knapsack (2차원 배열 버전)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> info;
int dp[101][10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, t; cin>>n>>t;
    info.push_back(make_pair(0, 0));
    
    for(int i=0; i<n; i++){
        int k, s; cin>>k>>s;
        info.push_back(make_pair(k, s));
    }
    
    for(int i=1; i<info.size(); i++){
        int times = info[i].first;
        int score = info[i].second;
        
        for(int j=0; j<=t; j++){ // j = 현재까지의 총 공부 시간
            if(j < times)
                dp[i][j] = dp[i-1][j];
            
            else
                dp[i][j] = max(dp[i-1][j-times] + score, dp[i-1][j]);
        }
    }

    cout<<dp[n][t]<<"\n";
    return 0;
}
