// 프로그래머스 Lv.2 행렬 테두리 회전하기

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries){ 
    vector<vector<int>> matrix(rows+1, vector<int>(columns+1));
    vector<vector<int>> rotation(rows+1, vector<int>(columns+1)); // 회전 시 변경되는 부분을 저장하는 vector
    vector<int> answer;
    
    int cnt = 1;
    for(int i=1; i<=rows; i++){
        for(int j=1; j<=columns; j++){
            matrix[i][j] = cnt;
            rotation[i][j] = cnt;
            cnt++;
        }
    }
    
    for(int i=0; i<queries.size(); i++){
        int x1 = queries[i][0];
        int y1 = queries[i][1];
        int x2 = queries[i][2];
        int y2 = queries[i][3];
        int minVal = 987654321;
        
        for(int next=y1+1; next<=y2; next++){ // x1 고정, y1~y2까지 한 칸씩 오른쪽으로 이동
            rotation[x1][next] = matrix[x1][next-1];
            minVal = min(rotation[x1][next], minVal);
        }
        
        for(int next=x1+1; next<=x2; next++){ // y2 고정, x1~x2까지 한 칸씩 아래로 이동
            rotation[next][y2] = matrix[next-1][y2];
            minVal = min(rotation[next][y2], minVal);
        }
        
        for(int next=y2-1; next>=y1; next--){ // x2 고정, y2~y1까지 한 칸씩 왼쪽으로 이동
            rotation[x2][next] = matrix[x2][next+1];
            minVal = min(rotation[x2][next], minVal);
        }
        
        for(int next=x2-1; next>=x1; next--){ // y1 고정, x2~x1까지 한 칸씩 위로 이동
            rotation[next][y1] = matrix[next+1][y1];
            minVal = min(rotation[next][y1], minVal);
        }
        
        matrix = {rotation.begin(), rotation.end()}; // 이번 턴에서의 변경 사항을 원본 matrix에 저장
        answer.push_back(minVal);
    }
    
    return answer;
}
