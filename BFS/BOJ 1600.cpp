#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int k, w, h;
int land[200][200];
bool visit[200][200][31];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int hx[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
int hy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int bfs(int x, int y){
    queue<pair<pair<int,int>, pair<int,int>>> q;
    visit[x][y][0] = true;
    q.push(make_pair(make_pair(x,y), make_pair(0,0)));
    
    while(!q.empty()){
        int curX = q.front().first.first;
        int curY = q.front().first.second;
        int horse = q.front().second.first;
        int move = q.front().second.second;
        q.pop();
            
        if(curX == h-1 && curY == w-1)
            return move;
        
        if(horse < k){
            for(int i=0; i<8; i++){
                int nx = curX + hx[i];
                int ny = curY + hy[i];
                
                if(nx >= 0 && nx < h && ny >= 0 && ny < w){
                    if(land[nx][ny] != 1 && !visit[nx][ny][horse+1]){
                        visit[nx][ny][horse+1] = true;
                        q.push(make_pair(make_pair(nx,ny), make_pair(horse+1, move+1)));
                    }
                }
            }
        }
        
        for(int i=0; i<4; i++){
            int nx = curX + dx[i];
            int ny = curY + dy[i];
            
            if(nx >= 0 && nx < h && ny >= 0 && ny < w){
                if(land[nx][ny] != 1 && !visit[nx][ny][horse]){
                    visit[nx][ny][horse] = true;
                    q.push(make_pair(make_pair(nx,ny), make_pair(horse, move+1)));
                }
            }
        }
    }
    return -1;
}

int main(){
    cin>>k>>w>>h;
    
    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
            cin>>land[i][j];
    
    int ans = bfs(0,0);
    
    cout<<ans<<endl;
    return 0;
}
