// 백준 G5 합분해
// dp[x][y] = x개의 숫자를 더해 y를 만들 수 있는 경우의 수

#include <iostream>
#include <string.h>
#define MOD 1000000000
using namespace std;

int main(){
    int n, k;
    int dp[202][202];
    cin>>n>>k;
    
    for(int i=0; i<=201; i++)
        memset(dp[i], 0, sizeof(int)*201);
    
    dp[0][0] = 1;
    for(int i=1; i<=k; i++){
        for(int j=0; j<=n; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= MOD;
        }
    }
    
    cout<<dp[k][n]<<"\n";
    return 0;
}
