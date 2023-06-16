// 프로그래머스 Lv.2 가장 큰 정사각형
// DP 기본 문제 => 예외처리 & dp 적용 아이디어 도출 연습

#include <vector>
#include <algorithm>
using namespace std;

int dp[1001][1001] = {0, };

int solution(vector<vector<int>> board){
    int answer = 0;
    int row = board.size(), col = board[0].size();
    
    vector<vector<int>> dp; 
    vector<int> tmp(col); // dp 배열의 맨 앞에 0 추가
    dp = board; dp.insert(dp.begin(), tmp);
    
    if(row == 1 && col == 1){ // board 사이즈가 1X1인 경우 
        if(board[0][0] == 0)
            return 0;
        else
            return 1;
    }
    
    for(int i=1; i<=row; i++){
        for(int j=1; j<=col; j++){
            if(dp[i][j] == 1){
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                answer = max(answer, dp[i][j]);
            }
        }
    }
        
    return answer*answer;
}
