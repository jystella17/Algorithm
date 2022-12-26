// 프로그래머스 LV.2 전력망을 둘로 나누기
// 완전탐색(BFS) - DFs도 가능

#include <string>
#include <vector>
#include <queue>
#include <cstdlib>
#include <iostream>
using namespace std;

int bfs(vector<vector<int>> graph, int v, int div){
    bool visited[101] = {false, };
    queue<int> q;
    q.push(v);
    visited[v] = true;
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        
        for(int i=1; i<graph[x].size(); i++){
            // 현재 송전탑과 연결되어 있으면서 이전에 탐색한 적 없는 송전탑 
            if(graph[x][i] && !visited[i]){
                visited[i] = true;
                q.push(i);
                div++; // 전력망에 포함된 송전탑 개수 + 1
            }
        }
    }
    
    return div;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 987654321;
    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
    
    // 연결된 두 송전탑에 대해 양방향 연결 정보 저장
    for(int i=0; i<wires.size(); i++){
        graph[wires[i][0]][wires[i][1]] = 1;
        graph[wires[i][1]][wires[i][0]] = 1;
    }
    
    for(int i=1; i<graph.size(); i++){
        for(int j=1; j<graph[i].size(); j++){
            if(graph[i][j]){
                // 두 송전탑을 연결하는 전선 끊기
                graph[i][j] = 0;
                graph[j][i] = 0;
                
                // 각 송전탑을 기준으로 전력망을 2개로 분할
                // 각 전력망에 포함된 송전탑 개수 구하기
                int div1 = bfs(graph, i, 1);
                int div2 = bfs(graph, j, 1);
                
                // 각 전력망에 포함된 송전탑 개수 차이를 구하고
                // 차이의 최솟값 업데이트
                int diff = abs(div1-div2);
                answer = min(answer, diff);
                
                // 다음 탐색을 위해 다시 두 송전탑 연결
                graph[i][j] = 1;
                graph[j][i] = 1;
            }
        }
    }
    
    
    return answer;
}
