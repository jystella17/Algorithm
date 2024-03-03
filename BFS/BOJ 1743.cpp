// 백준 S1 음식물 피하기

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// 1 = 음식물, 0 = 깨끗한 상태
int cafeteria[101][101] = {0, };
// 각 좌표를 기준으로 상하좌우 방향에 있는 음식물 쓰레기의 최대 크기
bool waste[101][101] = {false, };

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m, k, answer = 0;

void bfs(int x, int y){
    queue<pair<int, int>> queue;
    queue.push(make_pair(x, y));
    waste[x][y] = true; 
    int count = 1;
    
    while(!queue.empty()){
        int cx = queue.front().first;
        int cy = queue.front().second;
        queue.pop();
        
        for(int i=0; i<4; i++){
            int nx = dx[i] + cx;
            int ny = dy[i] + cy;
            
            if(nx <= 0 || nx > n || ny <= 0 || ny > m)
                continue;
            
            if(cafeteria[nx][ny] == 1 && !waste[nx][ny]){
                count++;
                waste[nx][ny] = true;
                queue.push(make_pair(nx, ny));
            }
        }
    }
    answer = max(answer, count);
}

int main(){
    cin>>n>>m>>k;
    vector<pair<int, int>> positions;
    
    for(int i=0; i<k; i++){
        int r, c; cin>>r>>c;
        
        cafeteria[r][c] = 1;
        positions.push_back(make_pair(r, c));
        
    }
    
    for(int i=0; i<positions.size(); i++){
        bfs(positions[i].first, positions[i].second);
    }
    
    cout<<answer<<"\n";
    return 0;
}
