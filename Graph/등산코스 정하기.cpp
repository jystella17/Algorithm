//다익스트라

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
typedef pair<int,int> pi;
const int INF=1e12;
vector<int> dist;

bool findTarget(vector<int> &arr, int target) {
    return find(arr.begin(), arr.end(), target)!=arr.end() ? true: false;
}

vector<int> dijkstra(int n, int start, vector<vector<pi>> &graph){
    vector<bool> visited(n+1, false);
    visited[start]=true;
    priority_queue<pi, vector<pi>, greater<>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        for (int i=0; i<graph[node].size(); i++) {
            int next = graph[node][i].first;
            int next_cost=max(graph[node][i].second, cost);
            if (visited[next]) continue;

            if (dist[next] > next_cost) {
                dist[next]=next_cost;
                pq.push({next_cost, next});
            }
        }
    }
    return dist;
}



vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer(2, INF);
    vector<vector<pi>> graph(n+1);
    dist.assign(n+1, INF);

    for (int i=0; i<paths.size(); i++) {
        int a=paths[i][0];
        int b=paths[i][1];
        int c=paths[i][2];

        if (findTarget(gates, a) || findTarget(summits, b)) {
            graph[a].push_back({b, c});
        }
        
        else if (findTarget(gates, b) || findTarget(summits, a)){
            graph[b].push_back({a, c});
        }
        
        else {
            graph[a].push_back({b, c});
            graph[b].push_back({a, c});
        }
    }

    for (auto gate: gates) {
        dijkstra(n, gate, graph);
    }

    for (auto summit: summits) {
        if (dist[summit]==answer[1]) {
            if (summit < answer[0]) {
                answer[0]=summit;
                answer[1]=dist[summit];
            }
        }
        
        else if (dist[summit] < answer[1]) {
            answer[0]=summit;
            answer[1]=dist[summit];
        }
    }

    return answer;
}
