// 프로그래머스 Lv.4 매출 하락 최소화
// 2021 Kakao Blind Recruitment 7번

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> organizations[300001];
int income[300001];
int dp[300001][2];

void workshop(int current){
    if(dp[current][1] > 0 && dp[current][0] > 0)
        return;
    
    dp[current][1] = income[current];
    int sum = 0;
    bool is_selected = false;

    for(int i=0; i<organizations[current].size(); i++){
        int next = organizations[current][i];
        
        if(dp[next][1] > 0 || dp[next][0] > 0)
            continue;
        
        workshop(next);
        
        if(dp[next][0] >= dp[next][1]){
            dp[current][1] += dp[next][1];
            is_selected = true;
            sum += dp[next][1];
        }
        
        else {
            dp[current][1] += dp[next][0];
            sum += dp[next][0];
        }
    }
    
    if(is_selected)
        dp[current][0] = sum;
    
    else{
        for(int i=0; i<organizations[current].size(); i++){
            int next = organizations[current][i];
            int tmp = sum - dp[next][0] + dp[next][1];
        
            if(dp[current][0] == 0)
                dp[current][0] = tmp;
        
            else dp[current][0] = min(tmp, dp[current][0]);
        }
    }
}

int solution(vector<int> sales, vector<vector<int>> links) {
    int answer = 0;
    
    for(int i=0; i<sales.size(); i++)
        income[i+1] = sales[i];
    
    for(int i=0; i<links.size(); i++){
        int a = links[i][0], b = links[i][1];
        
        organizations[a].push_back(b);
        //organizations[b].push_back(a);
    }
    
    for(int i=1; i<=sales.size(); i++)
        dp[i][1] = dp[i][0] = 0;
    
    workshop(1);
    
    answer = min(dp[1][1], dp[1][0]);
    return answer;
}
