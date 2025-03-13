// 2025 프로그래머스 코드챌린지 2차 예선 완전범죄 (Lv.2)

#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

// i번 물건을 훔치는 경우까지 고려했을 때, B의 흔적 개수 합이 1 ~ m-1인 경우 A의 흔적 개수 합의 최소 저장
int dp[121][121];

int solution(vector<vector<int>> info, int n, int m) {
    int answer = INF;
    
    for(int i=1; i<=info.size(); i++)
        for(int j=0; j<m; j++)
            dp[i][j] = INF;

    for(int i=1; i<=info.size(); i++){
        for(int j=0; j<m; j++){
            // i번 물건을 A가 훔치는 경우
            dp[i][j] = min(dp[i-1][j] + info[i-1][0], dp[i][j]);
        
            // i번 물건을 B가 훔치는 경우
            if(j + info[i-1][1] >= m) continue;
            dp[i][j + info[i-1][1]] = min(dp[i-1][j], dp[i][j + info[i-1][1]]);
        }
    }
    
    for(int i=0; i<m; i++)
        answer = min(answer, dp[info.size()][i]);

    return answer >= n ? -1 : answer;
}
