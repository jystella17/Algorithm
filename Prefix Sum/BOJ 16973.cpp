// 백준 G4 직사각형 탈출
// 누적합 개념 + BFS
// 직사각형 이동 조건에 유의

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, h, w;
int grid[1001][1001];
int move_count[1001][1001] = {0, };
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool is_wall(int sx, int sy, int dir){
    if(dir == 0){ // (1,0)
        int threshold = sx + h-1;
        if(threshold > n) // 오른쪽 끝의 x좌표가 grid 범위를 초과
            return true;
        
        for(int i=sy; i<sy+w; i++){
            if(grid[threshold][i] == 1)
                return true;
        }
    }
    
    else if(dir == 1){ // (-1, 0)
        for(int i=sy; i<sy+w; i++){
            if(grid[sx][i] == 1)
                return true;
        }
    }
    
    else if(dir == 2){ // (0, 1)
        int threshold = sy + w-1;
        if(threshold > m) // 아래쪽 끝의 y좌표가 grid 
            return true;
        
        for(int i=sx; i<sx+h; i++){
            if(grid[i][threshold] == 1)
                return true;
        }
    }
    
    else if(dir == 3){ // (0, -1)
        for(int i=sx; i<sx+h; i++){
            if(grid[i][sy] == 1)
                return true;
        }
    }
    
    return false;
}

int shortest_path(int sr, int sc, int fr, int fc){
    queue<pair<int, int>> q;
    q.push(make_pair(sr, sc));
    move_count[sr][sc] = 1;
    
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        if(cx == fr && cy == fc)
            break;
        
        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nx>0 && nx<=n && ny>0 && ny<=m && !move_count[nx][ny]){
                int next = is_wall(nx, ny, i);
                if(!next){
                    q.push(make_pair(nx, ny));
                    move_count[nx][ny] = move_count[cx][cy]+1;
                }
            }
        }
    }
    
    return move_count[fr][fc] - 1;
}

int main(){
    int sr, sc, fr, fc;
    cin>>n>>m;
    
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>grid[i][j];
            
    cin>>h>>w>>sr>>sc>>fr>>fc;
    
    int answer = shortest_path(sr, sc, fr, fc);
    cout<<answer<<endl;

    return 0;
}
