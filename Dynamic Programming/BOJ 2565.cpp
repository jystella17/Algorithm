// BOJ G5 전깃줄
// 최대/최장 증가 수열 (LIS, Longest Increasing Subsequence)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<pair<int, int>> electric;
    int dp[101] = {0, }; 
    int num, answer = 0; 
    cin>>num;
    
    electric.push_back(make_pair(0, 0));
    for(int i=0; i<num; i++){
        int start, dest;
        cin>>start>>dest;
        electric.push_back(make_pair(start, dest));
    }
    
    sort(electric.begin(), electric.end());
    
    for(int i=1; i<=num; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(electric[i].second > electric[j].second)
                dp[i] = max(dp[j]+1, dp[i]);
        }
        answer = max(answer, dp[i]);
    }
    
    cout<<num - answer<<"\n";
    return 0;
}
