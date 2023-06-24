// 백준 P5 KCM Travel
// 다익스트라 + DP

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int answer = INF;
int n, m, k;
// i -> flight[i].first로 가는 경로의 cost와 duration 저장
vector<pair<int, pair<int, int>>> flight[102];
// 1 -> i번 공항으로 가는 비용별 최소 소요시간 저장
int min_time[102][10002];

void dijkstra(){
    priority_queue<pair<int, pair<int, int>>> pq; // 소요시간, 공항 번호(인덱스), 비용
    pq.push(make_pair(0, make_pair(1, 0)));
    min_time[1][0] = 0;
    
    while(!pq.empty()){
        int duration = -pq.top().first;
        int index = pq.top().second.first;
        int cost = pq.top().second.second;
        pq.pop();
        
        if(min_time[index][cost] < duration) continue;

        for(int i=0; i<flight[index].size(); i++){
            int next_duration = duration + flight[index][i].first;
            int next_cost = cost + flight[index][i].second.first;
            int next_index = flight[index][i].second.second;
            
            if(next_cost > m) continue;
            
            if(next_duration < min_time[next_index][next_cost]){
                min_time[next_index][next_cost] = next_duration;
                // 현재까지 구한 소요시간이 최소임을 가정하면
                // 다음 공항으로 가는 비용이 더 많이 들면서 소요시간도 더 긴 경우는 해가 될 수 없음
                // 따라서 비용이 더 많이 드는 모든 경우에 대해 소요시간을 (현재까지의)최소값으로 업데이트
                for(int j=next_cost+1; j<=m && min_time[next_index][j]>next_duration; j++){
                    // 이미 최소값으로 업데이트 되어있는 경우 종료
                    if(min_time[next_index][j] <= next_duration) continue;
                    min_time[next_index][j] = next_duration;
                }
                pq.push(make_pair(-next_duration, make_pair(next_index, next_cost)));
            }
        }
    }
}

int main(){
    int t; scanf("%d", &t);
    
    while(t--){
        scanf("%d %d %d", &n, &m, &k);

        for(int i=1; i<=n; i++){
            flight[i].clear();
            
            for(int j=0; j<=m; j++)
                min_time[i][j] = INF;
        }
    
        for(int i=0; i<k; i++){
            int departure, destination, cost, duration;
            scanf("%d %d %d %d", &departure, &destination, &cost, &duration);
            flight[departure].push_back(make_pair(duration, make_pair(cost, destination)));
        }
        
        for(int i=1; i<=n; i++)
            sort(flight[i].begin(), flight[i].end());
        
        dijkstra();
        
        for(int i=0; i<=m; i++)
            if(min_time[n][i] < answer)
                answer=min_time[n][i];
        
        if(answer == INF)
            printf("Poor KCM\n");
        else
            printf("%d\n", answer);
    }

    return 0;
}
