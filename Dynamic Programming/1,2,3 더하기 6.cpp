// BOJ 15991 1,2,3 더하기 6 (S1)

#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int tc; cin>>tc;
    long long dp[100001];
    int mod = 1000000009;
    
    dp[1] = 1; dp[2] = 2; dp[3] = 2;
    dp[4] = 3; dp[5] = 3; dp[6] = 6;
    
    for(int i=7; i<=100000; i++){
        dp[i] = (dp[i-2] + dp[i-4] + dp[i-6]) % mod;
    }
    
    for(int t=0; t<tc; t++){
        int n; cin>>n;
        cout<<dp[n]<<"\n";
    }
}
