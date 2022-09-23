// 전깃줄 - 최대/최장 증가 수열 (LIS, Longest Increasing Subsequence)

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<pair<int, int>> electric;
    int dp[101] = {0, };
    int n;
    int ans = 0;
    cin>>n;
    
    electric.push_back(make_pair(0,0));
    for(int i=0; i<n; i++){
        int tx, ty;
        cin>>tx>>ty;
        electric.push_back(make_pair(tx,ty));
    }
    
    sort(electric.begin(), electric.end());

    for(int i=1; i<=n; i++){
        for(int j=0; j<i; j++){
            if(electric[i].second > electric[j].second){
                dp[i] = max(dp[j]+1, dp[i]);
            }
        }
        ans = max(ans, dp[i]);
    }
    
    cout<<n - ans<<endl;

    return 0;
}
