// 백준 G3 벽 부수고 이동하기

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <memory.h>
#include <algorithm>
#define INF 987654321
using namespace std;

int n, m;
int map[1001][1001];
int visited[1001][1001][2];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs(int x, int y){
    if(n == 1 && m == 1)
        return 1;

    queue<pair<pair<int, int>, int>> queue;
    queue.push(make_pair(make_pair(x, y), 0));
    visited[x][y][0] = 1;

    while(!queue.empty()) {
        int cx = queue.front().first.first;
        int cy = queue.front().first.second;
        int broken = queue.front().second;
        queue.pop();

        for (int i = 0; i < 4; i++) {
            int nx = dx[i] + cx;
            int ny = dy[i] + cy;

            if(nx == n && ny == m)
                return visited[cx][cy][broken] + 1;

            if (nx <= 0 || nx > n || ny <= 0 || ny > m)
                continue;

            // 이미 부순 벽이 있는데 또 다시 벽을 만나면 탐색 불가
            if(broken && map[nx][ny] == 1)
                continue;

            // flag 변경이 필요 없는 경우 (다음 칸이 벽이 아닌 경우)
            // broken == true && map[nx][ny] == 0 || broken == false && map[nx][ny] == 0
            if(map[nx][ny] == 0 && visited[nx][ny][broken] == -1){
                visited[nx][ny][broken] = visited[cx][cy][broken] + 1;
                queue.push(make_pair(make_pair(nx, ny), broken));
            }

            // 아직 벽을 부순 적이 없고, 다음 칸이 벽인 경우
            if(!broken && map[nx][ny] == 1 && visited[nx][ny][1] == -1){
                // 현재 벽 부수고 지나가기
                visited[nx][ny][1] = visited[cx][cy][0] + 1;
                queue.push(make_pair(make_pair(nx, ny), 1));
            }
        }
    }
    return -1;
}

int main(){
    vector<pair<int, int>> candidates;
    cin>>n>>m;

    for(int i=1; i<=n; i++){
        string input; cin>>input;

        for(int j=1; j<=m; j++){
            map[i][j] = (int) input[j-1] - '0';
        }
    }

    memset(visited, -1, sizeof(visited));

    cout<<bfs(1, 1)<<"\n";
    return 0;
}
