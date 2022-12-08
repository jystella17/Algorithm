// 프로그래머스 LV.3 경주로 건설
// 2020 카카오 인턴십 4번
// BFS
// 주의: 같은 좌표라도 어떤 방향에서 접근하느냐에 따라 다른 케이스로 생각해야 함

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int solution(vector<vector<int>> board) { 
    int answer = 2e9;
    int size = board.size();
    int cost[4][26][26]; 
    for(int d=0; d<4; d++)
        for(int i=0; i<size; i++)
            for(int j=0; j<size; j++)
                cost[d][i][j] = 2e9;
    
    cost[0][0][0] = 0;
    cost[2][0][0] = 0;
    // 단순 방문 여부 체크 X, 해당 위치까지의 '방향별' 최소 비용 저장
    // 시작 위치에서 가능한 방향은 (1,0), (0,1) 두가지이므로 둘다 queue에 저장 (탐색 대상)
    
    queue<pair<pair<int,int>, pair<int,int>>> road;
    road.push(make_pair(make_pair(0,0), make_pair(0,0)));
    road.push(make_pair(make_pair(0,0), make_pair(0,2)));
    
    while(!road.empty()){
        int cx = road.front().first.first;
        int cy = road.front().first.second;
        int prev_cost = road.front().second.first;
        int dir = road.front().second.second;
        road.pop();
        
        if(cx == size-1 && cy == size-1)
            answer = min(answer, prev_cost);

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx<0 || nx>=size || ny<0 || ny>=size || board[nx][ny] == 1)
                continue; // 도면 범위를 벗어나거나 다음 칸이 벽
            
            int new_cost;
            if(dir == i) // 같은 방향
                new_cost = prev_cost + 100;
                
            else
                new_cost = prev_cost + 600;
                
            if(cost[i][nx][ny] >= new_cost){
                cost[i][nx][ny] = new_cost; // 최소 비용으로 업데이트
                road.push(make_pair(make_pair(nx,ny), make_pair(new_cost,i)));
            }
        }
    }
    
    return answer;
}
