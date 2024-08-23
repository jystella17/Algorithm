// BOJ 2638 치즈 (G3)
// BFS 응용
// 처음 입력받은 후 or 내부공기를 외부공기로 전환할 때 BFS 사용

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, num_cheese = 0;
int grid_map[100][100] = {0, }; // 2 = 외부공기, 1 = 치즈, 0 = 내부공기
bool visited[100][100] = {false, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void init(){
    queue<pair<int, int>> outer;
    
    outer.push(make_pair(0, 0));
    outer.push(make_pair(0, m-1));
    outer.push(make_pair(n-1, 0));
    outer.push(make_pair(n-1, m-1));
    
    visited[0][0] = true; visited[n-1][m-1] = true;
    visited[0][m-1] = true; visited[n-1][0] = true;
    
    grid_map[0][0] = 2; grid_map[n-1][m-1] = 2;
    grid_map[0][m-1] = 2; grid_map[n-1][0] = 2;

    while(!outer.empty()){
        int x = outer.front().first;
        int y = outer.front().second;
        outer.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(grid_map[nx][ny] == 0 && !visited[nx][ny]) {
                grid_map[nx][ny] = 2;
                visited[nx][ny] = true;
                outer.push(make_pair(nx, ny));
            }
        }
    }
}

void in_to_out(){
    queue<pair<int, int>> to_change;
    fill(visited[0], visited[100], false);
    
    to_change.push(make_pair(0, 0));
    to_change.push(make_pair(0, m-1));
    to_change.push(make_pair(n-1, 0));
    to_change.push(make_pair(n-1, m-1));
    
    visited[0][0] = true; visited[n-1][m-1] = true;
    visited[0][m-1] = true; visited[n-1][0] = true;
     
    while(!to_change.empty()){
        int x = to_change.front().first;
        int y = to_change.front().second;
        to_change.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            
            if(grid_map[nx][ny] != 1 && !visited[nx][ny]){
                if(grid_map[nx][ny] == 0)
                    grid_map[nx][ny] = 2;
                
                visited[nx][ny] = true;
                to_change.push(make_pair(nx, ny));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>grid_map[i][j];
            
            if(grid_map[i][j]) num_cheese++;
        }
    }
    
    init();
    
    int answer = 0;
    while(num_cheese > 0){
        queue<pair<int, int>> cheese_to_air;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid_map[i][j] != 1) continue;
                
                int count = 0;
                for(int d=0; d<4; d++){
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(grid_map[nx][ny] == 2) count++;
                }
                
                if(count >= 2)
                    cheese_to_air.push(make_pair(i, j));
            }
        }
        
        while(!cheese_to_air.empty()){
            int x = cheese_to_air.front().first;
            int y = cheese_to_air.front().second;
            cheese_to_air.pop();
            
            num_cheese--;
            grid_map[x][y] = 2;
        }
        
        in_to_out();
        answer++;
    }
    cout<<answer<<"\n";
    return 0;
}
