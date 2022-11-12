// 프로그래머스 Lv.3 파괴되지 않은 건물
// 누적합(Prefix Sum)

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill){
    int n = board.size();
    int m = board[0].size();
    vector<vector<int>> attack_restore(n+1, vector<int>(m+1)); // 누적합(내구도 변화량) 저장
    int answer = 0;
    
    for(int s=0; s<skill.size(); s++){
        int type = skill[s][0];
        int r1 = skill[s][1];
        int c1 = skill[s][2];
        int r2 = skill[s][3];
        int c2 = skill[s][4];
        int degree = skill[s][5];
        
        if(type == 1)
            degree = -degree;
        
        attack_restore[r1][c1] += degree; // 누적합 개념 참고
        attack_restore[r1][c2 + 1] -= degree; // Reference: https://kimjingo.tistory.com/155
        attack_restore[r2 + 1][c1] -= degree;
        attack_restore[r2 + 1][c2 + 1] += degree;
    }
    
    for(int i=0; i<n; i++) // Row 기준 각 위치의 누적합 (각 건물에 대한 내구도 변화량)
        for(int j=0; j<m; j++)
            attack_restore[i][j+1] += attack_restore[i][j];
    
    for(int j=0; j<m; j++) // Column 기준  각 위치의 누적합 (각 건물에 대한 내구도 변화량)
        for(int i=0; i<n; i++)
            attack_restore[i+1][j] += attack_restore[i][j];
    
    // 내구도 변화량 + 최초 내구도
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(board[i][j] + attack_restore[i][j] > 0)
                answer++;
    
    return answer;
}
