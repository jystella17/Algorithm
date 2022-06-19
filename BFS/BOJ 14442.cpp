#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n, m, k;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int map[1001][1001];
bool visit[1001][1001][11];

int bfs(int sx, int sy){
    queue<pair<pair<int,int>, pair<int,int>>> q;
    q.push(make_pair(make_pair(sx,sy), make_pair(0,1)));
    visit[sx][sy][0] = true;
    
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int wall = q.front().second.first;
        int minDist = q.front().second.second;
        q.pop();
        
        if(x == n-1 && y == m-1)
            return minDist;
        
        if(wall < k){
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                    if(map[nx][ny] && !visit[nx][ny][wall+1]){
                        visit[nx][ny][wall+1] = true;
                        //map[nx][ny] = 0;
                        q.push(make_pair(make_pair(nx,ny), make_pair(wall+1,minDist+1)));
                    }
                }
            }
        }
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                if(!map[nx][ny] && !visit[nx][ny][wall]){
                    visit[nx][ny][wall] = true;
                    q.push(make_pair(make_pair(nx,ny), make_pair(wall,minDist+1)));
                }
            }
        }
    }
    
    return -1;
}

int main(){
    cin>>n>>m>>k;
    
    for(int i=0; i<n; i++){
        string tmp;
        cin>>tmp;
        for(int j=0; j<m; j++){
            map[i][j] = tmp[j] - '0';
        }
    }
            
    int ans = bfs(0,0);
    cout<<ans<<endl;
    
    return 0;
}
