// 프로그래머스 LV.2 빛의 경로 사이클
// DFS 개념 + Recursion
// 주의: 방향값을 저장하는 공간 필요 => 3차원 배열

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool grid_board[501][501][4]; // 좌표와 방향을 저장하는 3차원 배열
// Up:0, Down:1, Left:2, Right:3
vector<string> map;

int changeDir(int dir, char alpha){
    if(alpha == 'L'){
        if(dir == 0) return 2;
        else if(dir == 1) return 3;
        else if(dir == 2) return 1;
        else return 0; // dir == 3
    }
    
    else{ // alpha == 'R'
        if(dir == 0) return 3;
        else if(dir == 1) return 2;
        else if(dir == 2) return 0;
        else return 1; // dir == 3
    }
}

int lightCycle(int x, int y, int dir, int len){
    if(grid_board[x][y][dir])
        return len;
    
    grid_board[x][y][dir] = true;
    
    int ndir = dir;
    if(map[x][y] != 'S') // L, R이어서 방향 전환이 필요한 경우
        ndir = changeDir(dir, map[x][y]);
    
    int nx = x + dx[ndir];
    int ny = y + dy[ndir];
    
    // 격자 범위를 벗어나는 경우
    if(nx < 0)
        nx = map.size() - 1;
    else if(ny < 0)
        ny = map[0].size() - 1;
    
    if(nx == map.size())
        nx = 0;
    else if(ny == map[0].size())
        ny = 0;
    
    return lightCycle(nx, ny, ndir, len+1);
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    map = grid;
    
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[i].size(); j++){
            for(int k=0; k<4; k++){
                int cycle_len = lightCycle(i, j, k, 0);
                
                if(cycle_len)
                    answer.push_back(cycle_len);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}
