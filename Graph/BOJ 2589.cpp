#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){ // bfs(최단거리를 찾는 것이 목적 >> 현재 위치에서 탐색 가능한 모든 경로를 선택해서 탐색하며 최단 거리를 구함)
    char map[50][50];
    int dist[50][50];
    queue<pair<int, int>> land;
    int m, n;
    int ans = 0;
    
    cin>>m>>n;
    
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>map[i][j];
            
            if(map[i][j] == 'L')
                land.push(make_pair(i,j)); // 지나갈 수 있는 위치 (육지) 만 따로 저장
        }
    }
    
    while(!land.empty()){
        int startx = land.front().first;
        int starty = land.front().second;
        land.pop();
        
        memset(dist, 0, sizeof(dist));
        
        queue<pair<int,int>> q;
        q.push(make_pair(startx,starty)); // 시작 위치가 정해져있지 않으므로, 미리 저장된 육지의 좌표값들을 각각 출발점으로 설정하고 탐색해야 함
        
        while(!q.empty()){ // bfs 코드
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx>=0 && nx<m && ny>=0 && ny<n){ // nx, ny 값이 올바른 좌표 범위 내에 있을 때
                    if(map[nx][ny] == 'L' && (nx != startx || ny != starty)){ // nx, ny가 탐색 가능한 위치 (육지) 이면서, 이미 지나갔던 위치를 중복으로 방문하지 않을 때
                        if(!dist[nx][ny] || dist[nx][ny] > dist[x][y] + 1){ // 한 번도 방문하지 않았거나, 이전에 탐색하며 구한 경로보다 더 짧은 경로가 존재하는 경우
                            dist[nx][ny] = dist[x][y] + 1; // 거리 값 업데이트
                            q.push(make_pair(nx,ny)); // 이동한 위치에서 다시 탐색을 수행하기 위해 이동한 위치를 queue에 저장
                        }
                    }
                }
            }
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(dist[i][j])
                    ans = max(ans, dist[i][j]); // 한 시작 정점에서의 탐색이 끝났을 때, 거리의 최대값 (==두 개의 보물을 모두 방문) 을 구함
                    // 이미 dist 배열에는 최소값들만 저장되어 있으므로, 최소값들 중 가장 큰 값 == 최단거리가 될 수 있음.
            }
        }
    }
    cout<<ans<<endl;
    
    return 0;
}
