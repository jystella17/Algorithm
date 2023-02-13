// 백준 G3 소문난 칠공주
// Backtracking + BFS + Simulation

#include <iostream>
#include <queue>
#include <cstring>
 
using namespace std;
 
int ans = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

char classroom[5][5];
int dasom[5][5];
bool visited[5][5] = {false, };
bool selected[26] = {false, }; // 인덱스 = 각 자리에 앉은 학생의 소속
 
bool isValid(int x, int y){
    return (x>=0 && x<5) && (y>=0 && y<5);
}
 
 
// 서로 인접한 자리에 앉아있는지 확인 
bool is_team(){
    memset(dasom, 0, sizeof(dasom));
    memset(visited, false, sizeof(visited));
    
    int x, y;
    for(int i=0; i<25; i++){
        if(!selected[i]) 
            continue;
        
        x = i%5;
        y = i/5;
        dasom[x][y] = 1;
    }
    
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = 1;
    
    int cnt = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(!isValid(nx, ny)) 
                continue;
            if(visited[nx][ny]) 
                continue;
            
            if(dasom[nx][ny] == 1) {
                cnt++;
                q.push(make_pair(nx, ny));
                visited[nx][ny] = true;
            }
        }
    }
    
    if(cnt == 7) 
        return true;
    else 
        return false;
}
 
// 인접한 7명의 학생을 선택하는 경우의 수 (조합)
void dfs(int student, int members, int cnt){
    if(members == 7){
        if(cnt >= 4)
            if(is_team())
                ans++;
                
        return;
    }
    
    for(int i=student; i<25; i++){
        if(selected[i]) 
            continue;
        
        selected[i] = true;
        dfs(i, members+1, cnt + (classroom[i%5][i/5] == 'S'));
        selected[i] = false;
    }
}
 
 
int main(){
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
            cin >> classroom[i][j];
    
    dfs(0, 0, 0);
    cout<<ans<<"\n";
}
