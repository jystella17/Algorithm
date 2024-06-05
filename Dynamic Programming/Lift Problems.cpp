// BOJ 10284 Lift Problems (G3)

#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

// dp[i][j] = 엘리베이터가 i층까지 이동하면서 j층에서 마지막으로 문이 열렸을 때
// lift anger의 최소값
int dp[1502][1502];
int button_count[1501];

int under_sum(int base){
    int result = 0;
    
    for(int i=base; i>=0; i--){
        result += (i * button_count[base-i+1]);
    }
    return result;
}

int calc_sum(int start, int end){
    int result = 0;
    
    for(int i=start; i<=end; i++){
        result += button_count[i];
    }
    return result;
}

int main(){
    int tc; cin>>tc;
    for(int t=1; t<=tc; t++){
        int n; cin>>n;
        
        for(int i=1; i<=n; i++){
            cin>>button_count[i];
        }
        
        for(int i=1; i<=n; i++){
            // dp[i][0] = (i * button_count[1] + ... + 1 * button_count[i])
            dp[i][0] = under_sum(i);
            
            int remains = 0;
            // dp[i][1 ~ i-1] = dp[i-1][j] + (button_count[j+1] + ... + button_count[i])
            // 1 <= j < n and j < i
            for(int j=i-1; j>=1; j--){
                remains += button_count[j+1];
                dp[i][j] = (dp[i-1][j] + remains);
            }
            
            // dp[i][i] = min(dp[i-1][0], dp[i][1], ..., dp[i][i-1]) + sum(cnt[i+1] ~ cnt[n])
            dp[i][i] = dp[i-1][0];
            for(int j=1; j<i; j++){
                dp[i][i] = min(dp[i][i], dp[i-1][j]);
            }
            dp[i][i] += calc_sum(i+1, n);
        }
        cout<<dp[n][n]<<"\n";
    }
    return 0;
}
