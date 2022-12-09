// 프로그래머스 LV.3 합승 택시 요금
// 2021 카카오 신입공채 1차 4번
// Priority Queue(우선순위 큐) + Dijkstra(다익스트라)

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

void dijkstra(vector<vector<int>>& graph, vector<int>& min_taxi, int n, int start){
    priority_queue<pair<int,int>> pq;
    min_taxi[start] = 0;
    pq.push(make_pair(start,0));
    
    while(!pq.empty()){
        int current = pq.top().first;
        int dist = pq.top().second;
        pq.pop();
        
        if(min_taxi[current] < dist) // 이미 최소 비용을 구했다면
            continue;
        
        for(int i=1; i<=n; i++){
            if(graph[current][i] == 0)
                continue;
            
            int nDist = graph[current][i] + dist;
            if(nDist < min_taxi[i]){
                min_taxi[i] = nDist;
                pq.push(make_pair(i, nDist));
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
    
    for(int i=0; i<fares.size(); i++){ // 출발 지점과 목적지에 따라 비용을 저장
        graph[fares[i][0]][fares[i][1]] = fares[i][2];
        graph[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    // 무향 그래프이므로 m->n의 비용 = n->m의 비용
    // 따라서 S->A의 최소 비용 = A->S의 최소 비용임을 이용해, 
    // 목적지인 A,B에서 다른 지점들까지의 거리를 구한다.
    
    // A에서 다른 정점들까지의 최소 비용
    vector<int> cost_fromA(n+1, INF); // 시작 정점에서 각 정점까지의 최소 비용
    dijkstra(graph, cost_fromA, n, a);
    
    // B에서 다른 정점들까지의 최소 비용
    vector<int> cost_fromB(n+1, INF);
    dijkstra(graph, cost_fromB, n, b);
    
    // S->i 최소 비용 (적합한 i 값을 알지 못하므로 모든 정점에 대해 구해야 함)
    vector<int> cost_fromS(n+1, INF);
    dijkstra(graph, cost_fromS, n, s);
    
    for(int i=1; i<=n; i++){
        int cost = cost_fromS[i] + cost_fromA[i] + cost_fromB[i];
        
        if(cost < answer && cost > 0)
            answer = cost;
    }
    
    return answer;
}
