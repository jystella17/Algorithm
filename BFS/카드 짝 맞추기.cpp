// 프로그래머스 LV.3 카드 짝 맞추기
// 2021 카카오 신입공채 1차 6번
// 입력값이 작아 완전탐색 가능 -> BFS
// 남은 카드를 제거하는 순서를 순열로 미리 구함 (algorithm 헤더의 next_permutation 함수)
// 순열에 따라 BFS로 탐색하면서 최소 조작 횟수를 구함

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> left_cards; // 남은 카드들의 번호
vector<vector<int>> boards;
int x, y; // 각 카드를 제거하기 위한 최소 경로를 탐색할 때
// 시작 위치 지정 (입력으로 주어지는 (r,c) 혹은 마지막으로 제거한 카드의 좌표)

int bfs(int dest){
    bool visited[4][4] = {false, };
    visited[x][y] = true;
    
    queue<pair<pair<int, int>,int>> q;
    q.push(make_pair(make_pair(x,y), 0));
    
    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int count = q.front().second;
        q.pop();
        
        if(boards[cx][cy] == dest){ // 찾으려는 카드에 도착하면
            x = cx, y = cy;
            // 다음 출발 위치를 현재 카드 위치로 변경
            boards[cx][cy] = 0; // 찾은 카드 제거
            
            return count+1; // Enter 횟수 1회 추가
        }
        
        // 상하좌우 1칸씩 움직이는 경우
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx<0 || nx>=4 || ny<0 || ny>=4)
                continue;
            
            if(!visited[nx][ny]){
                q.push(make_pair(make_pair(nx,ny), count+1));
                visited[nx][ny] = true;
            }
        }
        
        // Ctrl + 상하좌우
        for(int i=0; i<4; i++){
            int nx = cx;
            int ny = cy;
            
            while(nx+dx[i]>=0 && nx+dx[i]<4 && ny+dy[i]>=0 && ny+dy[i]<4){    
                nx += dx[i];
                ny += dy[i];
                
                if(boards[nx][ny]) // 출발 후 첫번째로 찾아지는 카드
                    break;
            }
            
            if(!visited[nx][ny]){
                q.push(make_pair(make_pair(nx,ny), count+1));
                visited[nx][ny] = true;
            }
        }
    }
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 987654321;
    
    // 제거해야 할 카드 번호와 위치 저장
    bool is_exist[7] = {false, };
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(board[i][j])
                is_exist[board[i][j]] = true;
        }
    }
    
    for(int i=1; i<7; i++){
        if(is_exist[i])
            left_cards.push_back(i);
    }
    
    // 순열을 이용해 가능한 카드 제거 순서 조합을 구함
    // 시작 위치 (r,c)에서 순열의 각 원소를 제거할 때 
    do{
        boards = board; //제거 대상 카드가 바뀔 때 원래 입력값으로 초기화
        x = r, y = c;
        
        int tmp = 0;
        for(int i=0; i<left_cards.size(); i++){ // 순열의 각 원소마다
            tmp += bfs(left_cards[i]); // 해당 번호 중 첫 번째로 찾아지는 카드
            tmp += bfs(left_cards[i]); // 두 번째로 찾아지는 카드
        }
        answer = min(answer, tmp);
    }while(next_permutation(left_cards.begin(), left_cards.end()));

    return answer;
}
