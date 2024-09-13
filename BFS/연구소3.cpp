// BOJ 17142 연구소 3 (G3)
// Combination + BFS 응용
// 케이스 구분에 주의
// 초기에 비활성 바이러스가 위치한 칸은 BFS 과정에서는 고려되어야 하지만 최종 답을 구할 때는 제외되어야 함

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
int lab[50][50], lab_cp[50][50];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<pair<int, int>> viruses;
bool selected[11];
vector<vector<pair<int, int>>> activated;

void combination(int idx, int count, int target){
    if(count == target){
        vector<pair<int, int>> start_coord;

        for(int i=0; i<viruses.size(); i++){
            if(selected[i])
                start_coord.push_back(make_pair(viruses[i].first, viruses[i].second));
        }
        activated.push_back(start_coord);
        return;
    }

    if(idx == viruses.size())
        return;

    for(int i=idx; i<viruses.size(); i++){
        if(selected[i]) continue;

        selected[i] = true;
        combination(i+1, count+1, target);
        selected[i] = false;
    }
}

int contagion(vector<pair<int, int>> start_points){
    queue<pair<int, int>> queue;
    int time_count[50][50];
    fill(time_count[0], time_count[n], 987654321);
    // 전체적으로는 큰 값으로 초기화, 처음 활성화하는 바이러스가 있는 위치와 벽이 있는 위치는 0으로 업데이트
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(lab_cp[i][j] == 1)
                time_count[i][j] = 0;
        }
    }

    for(int i=0; i<start_points.size(); i++){
        int x = start_points[i].first;
        int y = start_points[i].second;

        queue.push(make_pair(x, y));
        time_count[x][y] = 0;
        lab_cp[x][y] = 3; // 활성 바이러스 = 3
    }

    while(!queue.empty()){
        int x = queue.front().first;
        int y = queue.front().second;
        queue.pop();

        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(lab_cp[nx][ny] == 1 || lab_cp[nx][ny] == 3) continue;
            if(time_count[nx][ny] < 987654321) continue;

            // 빈 칸 or 비활성 바이러스가 있는 칸이면서, 방문한 적 없는 경우만 queue push
            time_count[nx][ny] = time_count[x][y] + 1;
            queue.push(make_pair(nx, ny));
            lab_cp[nx][ny] = 3; // 활성 바이러스가 있는 칸으로 업데이트
        }
    }

    int times = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // 모든 빈칸에 활성 바이러스가 퍼지는 시간을 구해야 하므로, 원래 비활성 바이러스가 있던 칸은 고려하지 않음
            if(lab[i][j] == 2) continue;
            times = max(time_count[i][j], times);
        }
    }
    return times;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>lab[i][j];

            if(lab[i][j] == 2)
                viruses.push_back(make_pair(i, j));
        }
    }

    for(int i=1; i<=m; i++) {
        combination(0, 0, i);
    }

    int answer = 987654321;
    for(int i=0; i<activated.size(); i++){
        for(int r=0; r<n; r++)
            for(int c=0; c<n; c++)
                lab_cp[r][c] = lab[r][c];

        int tmp_times = contagion(activated[i]);
        answer = min(tmp_times, answer);
    }

    if(answer == 987654321){ // 벽에 의해 활성 바이러스가 모든 빈칸으로 이동할 수 없는 경우
        cout<<-1<<"\n";
    } else{
        cout<<answer<<"\n";
    }
    return 0;
}
