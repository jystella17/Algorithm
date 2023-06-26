// 백준 G3 11066번 파일 합치기

#include <iostream>
using namespace std;

int main() {
    int t; cin>>t;
    int novel[501];
    int psum[501]; 
    int num[501][501];
    int dp[501][501];
    
    while (t--) {
        int n; cin>>n;

        for(int i=1; i<=n; i++){
            cin>>novel[i];
            psum[i] = psum[i-1] + novel[i];
        }
            
        for(int i=1; i<=n; i++)
            num[i-1][i] = i;
            
        for(int d=2; d<=n; d++){
            for(int i=0; i+d<=n; i++){
                int j = i + d;
                dp[i][j] = 2e9;
                
                for(int k=num[i][j-1]; k<=num[i+1][j]; k++){
                    int v = dp[i][k] + dp[k][j] + psum[j] - psum[i];
                    
                    if(dp[i][j] > v)
                        dp[i][j] = v, num[i][j] = k;
                }
            }
        }
        cout<<dp[0][n];
    }
    return 0;
}
