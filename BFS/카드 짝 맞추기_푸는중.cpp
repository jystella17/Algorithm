// 프로그래머스 LV.3 카드 짝 맞추기
// 2021 카카오 신입공채 1차 6번
// 입력값이 작아 완전탐색 가능 -> BFS
// 남은 카드를 제거하는 순서를 순열로 미리 구함 (algorithm 헤더의 next_permutation 함수)
// 순열에 따라 BFS로 탐색하면서 최소 조작 횟수를 구함

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
bool visited[4][4];
vector<int> left_cards; // 남은 카드들의 번호
vector<pair<int, int>> card_pos[7]; // 남은 카드들의 위치

int bfs(vector<vector<int>> board, int x, int y, int cnt){
    queue<pair<pair<int, int>, int>> q;
    q.push(make_pair(make_pair(x,y), cnt));
    visited[x][y] = true;
    
    while(!q.empty()){
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int count = q.front().second;
        q.pop();
        
        if(){ // 남은 카드가 없다면
            return count;
        }
        
        // 상하좌우 1칸씩 움직이는 경우
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(!visited[nx][ny]){
                q.push(make_pair(make_pair(nx,ny), count+1));
                visited[nx][ny] = true;
            }
        }
        
        // Ctrl + 상하좌우
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            while(1){
                if(nx<0 || nx>3 || ny<0 || ny>3){ //마지막칸
                    nx -= dx[i];
                    ny -= dy[i];
                    break;
                }
                
                if(board[nx][ny] > 0) // 첫번째로 찾아지는 카드
                    break;
                
                nx += dx[i];
                ny += dy[i];
            }
            
            if(!visited[nx][ny]){
                q.push(make_pair(make_pair(nx,ny), count+1));
                visited[nx][ny] = true;
            }
        }
    }
}

int delete_Cards(vector<vector<int>> board, int r, int c, int card){
    
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = 987654321;
    
    // 제거해야 할 카드 번호와 위치 저장
    vector<bool> is_exist(7, false);
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            int card = board[i][j];
            if(card > 0){
                card_pos[card].push_back(make_pair(i,j));
                if(!is_exist[card]){
                    is_exist[card] = true;
                    left_cards.push_back(card);
                }
            }
        }
    }
    
    // 남은 카드 각각을 첫 번째 제거 대상으로 할 때 조작 횟수
    for(int i=0; i<left_cards.size(); i++){
        answer = min(answer, delete_Cards(board, r, c, left_cards[i]));
    }

    return answer;
}
