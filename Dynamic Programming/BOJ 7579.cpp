// 7579 앱
// 0/1 Knapsack Problem

#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int bytes[101];
int cost[101];
int dp[10001] = {0, };

int main(){
    int n,m;
    int ans=INF;
    cin>>n>>m;
    
    for(int i=1; i<=n; i++)
        cin>>bytes[i];
       
    for(int i=1; i<=n; i++)
        cin>>cost[i];
        
    for(int i=1; i<=n; i++){
        for(int j=10000; j>=cost[i]; j--){
            dp[j] = max(dp[j], dp[j-cost[i]] + bytes[i]);
            
            if(dp[j] >= m)
                ans = min(ans,j);
        }
    }
    
    cout<<ans<<endl;
    
    return 0;
}
