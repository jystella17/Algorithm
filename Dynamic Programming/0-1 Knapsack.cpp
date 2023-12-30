// 0-1 Knapsack (각 단위를 주어진 만큼만 사용 가능한 경우) 예제 코드
// 코드트리 Novice High - Knapsack2 참고

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<pair<int, int>> jewel;
    jewel.push_back(make_pair(0, 0)); // dummy data (idx가 1부터 시작하도록)
    jewel.push_back(make_pair(2, 3));
    jewel.push_back(make_pair(6, 5));
    jewel.push_back(make_pair(2, 4));
    jewel.push_back(make_pair(3, 2));
    jewel.push_back(make_pair(4, 3));
    
    jewel.push_back(make_pair(5, 3));
    jewel.push_back(make_pair(4, 2));
    jewel.push_back(make_pair(6, 6));
    jewel.push_back(make_pair(7, 9));
    jewel.push_back(make_pair(10, 8));
    
    // dp 배열 전체를 임의의 최소값으로 초기화
    int dp[11][21]; fill(&dp[0][0], &dp[10][20], -987654321);
    // 아무 보석도 고려하지 않고, 가방에 넣을 수 있는 최대 무게도 0인 경우
    // 가능한 보석 가치의 최대 합 = 0
    dp[0][jewel[0].first] = jewel[0].second;
    
    // 1번 보석부터 i번 보석까지 고려한 값 저장
    for(int i=1; i<jewel.size(); i++){
        // 1~i번 보석을 고려하면서, 해당 보석들 중 일부 혹은 전체를 선택하여
        // 만들 수 있는 무게가 j인 경우의 가치 합 저장
        for(int j=0; j<=20; j++){
            // i번 보석까지 고려한 무게 합 - i번 보석의 무게 
            // = i-1번 보석까지 고려한 무게 합
            int prev = j - jewel[i].first;
            
            if(prev >= 0) // i번 보석을 넣을 수 있는 경우
                // i-1번 보석까지만 고려하여 무게 j를 만들었을 때의 최대 가치와
                // i번 보석을 넣어 무게 j를 만들었을 때의 최대 가치 중
                // 더 큰 값으로 dp 배열 업데이트
                dp[i][j] = max(dp[i-1][j], dp[i-1][prev] + jewel[i].second);
            
            else // // i번 보석을 넣을 수 없는 경우
                dp[i][j] = dp[i-1][j]; // i-1번 보석까지 고려했을 때의 최대 가치
        }
    }
    
    for(int i=0; i<jewel.size(); i++){
        for(int j=0; j<=20; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
