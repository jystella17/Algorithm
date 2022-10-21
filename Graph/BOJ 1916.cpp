// 백준 최소비용 구하기, 다익스트라(dp+bfs)

#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;

vector<pair<int, int>> bus[1001]; // 각 정점과 가중치를 저장
int cost[1001]; // 특정 정점까지의 가중치 중 최소값을 저장

void minCost(int start){
    priority_queue<pair<int, int>> pq; // 인접 정점들로 이동할 때 목적지와 해당 정점에서의 가중치 저장
    cost[start] = 0;
    pq.push(make_pair(cost[start], start));
    
    while(!pq.empty()){
        int cur = pq.top().second;
        int curCost = pq.top().first*-1;
        pq.pop();
        
        if(cost[cur] < curCost) // 현재 정점까지의 가중치 합이 이미 최소값이면 더이상 탐색하지 않고 continue
            continue;
        
        for(int i=0; i<bus[cur].size(); i++){ // 현재 정점과 연결된 모든 인접 정점들에 대해 탐색
            int next = bus[cur][i].first;
            int nextCost = curCost + bus[cur][i].second;

            if(cost[next] > nextCost){ // 다음 정점을 한번도 방문하지 않았거나, 방문했지만 최소값이 저장된 것은 아닐 경우
                cost[next] = nextCost;
                pq.push(make_pair(nextCost*-1, next));
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, dept, dest;
    cin>>n>>m;
    
    for(int i=1; i<=n; i++)
        cost[i] = INF;
    
    for(int i=0; i<m; i++){
        int a, b, cost;
        cin>>a>>b>>cost;
        bus[a].push_back(make_pair(b, cost));
    }
    
    cin>>dept>>dest;
    
    minCost(dept);
    
    cout<<cost[dest]<<endl;
    return 0;
}
