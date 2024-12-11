// BOJ 14728 벼락치기 (G5)
// 0-1 Knapsack (1차원 배열 버전)

#include <iostream>
#include <algorithm>
using namespace std;

// dp[i] : 총 공부 시간이 i 일 때 얻을 수 있는 최대 점수
int dp[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int n, t; cin>>n>>t;
    
    for(int i=0; i<n; i++){
        int k, s; cin>>k>>s;

        for(int j=t; j>=k; j--){
            dp[j] = max(dp[j-k] + s, dp[j]);
        }
    }

    cout<<dp[t]<<"\n";
    return 0;
}
