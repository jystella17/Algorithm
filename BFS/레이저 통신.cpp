// BOJ G3 6087번 레이저 통신
// 방향을 고려한 BFS + 구현

#include <iostream>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int w, h, answer = INF;
    pair<int, int> start = make_pair(-1, -1);
    pair<int, int> end;
    char map[101][101];
    int visited[4][101][101];
    fill(&visited[0][0][0], &visited[3][100][100], INF);

    // 동 남 서 북
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    cin>>w>>h;
    
    for(int i=0; i<h; i++){
        for(int j=0; j<w; j++){
            cin>>map[i][j];

            if(map[i][j] == 'C' and start.first == -1)
                start = make_pair(i, j);

            else if(map[i][j] == 'C' and start.first != -1)
                end = make_pair(i, j);
        }
    }

    queue<pair<int, pair<int, int>>> queue;
    for(int i=0; i<4; i++){
        // 0 = 동, 1 = 남, 2 = 서, 3 = 북
        queue.push(make_pair(i, make_pair(start.first, start.second)));
        visited[i][start.first][start.second] = 0;
    }

    while(!queue.empty()){
        int cx = queue.front().second.first;
        int cy = queue.front().second.second;
        int dir = queue.front().first;
        queue.pop();

        for(int i=0; i<4; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            int mirrors = visited[dir][cx][cy];

            if(nx < 0 or nx >= h or ny < 0 or ny >= w or map[nx][ny] == '*')
                continue;
            
            // 해당 방향을 선택하려면 회전이 필요한 경우
            if((dir+2) % 2 != i % 2)
                mirrors += 1;
            
            // 다음 칸을 방문한 적이 없거나, 더 적은 거울 개수로 도달할 방법이 있다면 업데이트
            if(visited[i][nx][ny] > mirrors){
                visited[i][nx][ny] = mirrors;
                queue.push(make_pair(i, make_pair(nx, ny)));
            }
        }
    }

    for(int i=0; i<4; i++){
        if(answer > visited[i][end.first][end.second])
            answer = visited[i][end.first][end.second];
    }
    cout<<answer<<"\n";
    return 0;
}
