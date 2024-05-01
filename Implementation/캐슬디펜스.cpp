// BOJ 17135 캐슬디펜스 (G3)

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n, m, d, answer = -1;
int map[15][15], map_copy[15][15], positions[15];
vector<vector<int>> archers;

// 궁수 위치 조합 = 15C3 = 455
void pos_archers(int idx, int cnt){
    if(idx == m){
        if(cnt != 3)
            return;

        vector<int> tmp;

        for(int i=0; i<m; i++){
            if(positions[i] == 1)
                tmp.push_back(i);
        }
        archers.push_back(tmp);
        return;
    }

    positions[idx] = 1;
    pos_archers(idx+1, cnt+1);
    positions[idx] = 0;
    pos_archers(idx+1, cnt);
}

int calc_distance(int ax, int ay, int ex, int ey){
    return abs(ax - ex) + abs(ay - ey);
}

pair<int, int> attack_pos(int x, int y){
    pair<int, int> ret = make_pair(100, 100);
    int min_dist = 987654321;

    // 타겟 지정 우선 순위 => 1. 궁수와의 거리 최소 / 2. 궁수와의 거리가 같은 경우 가장 왼쪽 (m이 최소)
    int threshold = x-d ? x-d >= 0 : 0;
    // 턴이 바뀔 때마다 map 전체를 업데이트하지 않고, 궁수의 x좌표를 1씩 감소시키면 적이 아래로 1칸씩 이동하는 것과 같은 효과
    for(int i=x-1; i>=threshold; i--){
        for(int j=0; j<m; j++){
            if(map_copy[i][j] == 1){
                int cur_dist = calc_distance(x, y, i, j);
                if(cur_dist > d || cur_dist > min_dist)
                    continue;

                if(cur_dist == min_dist)
                    if(ret.second < j)
                        continue;

                ret = make_pair(i, j);
                min_dist = cur_dist;
            }
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n>>m>>d;

    for(int i=0; i<n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            map_copy[i][j] = map[i][j];
        }
    }

    pos_archers(0, 0);

    for(auto arc : archers){
        int cnt = 0;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                map_copy[i][j] = map[i][j];

        for(int bound=n; bound>0; bound--){
            pair<int, int> pos1 = attack_pos(bound, arc[0]);
            pair<int, int> pos2 = attack_pos(bound, arc[1]);
            pair<int, int> pos3 = attack_pos(bound, arc[2]);

            if(pos1.first != 100 && pos1.second != 100 && map_copy[pos1.first][pos1.second] != 0) {
                map_copy[pos1.first][pos1.second] = 0;
                cnt++;
            }

            if(pos2.first != 100 && pos2.second != 100 && map_copy[pos2.first][pos2.second] != 0){
                map_copy[pos2.first][pos2.second] = 0;
                cnt++;
            }

            if(pos3.first != 100 && pos3.second != 100 && map_copy[pos3.first][pos3.second] != 0){
                map_copy[pos3.first][pos3.second] = 0;
                cnt++;
            }
        }
        answer = max(answer, cnt);
    }

    cout<<answer<<"\n";
    return 0;
}
