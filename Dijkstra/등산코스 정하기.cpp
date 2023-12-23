// 프로그래머스 Lv.3 등산코스 정하기
// 2022 Kakao Tech Internship 기출
// 모든 출입구에서 모든 산봉우리까지의 intensity를 구할 때, 각 출입구 하나하나를 고려해서 for문 + dijskstra로 설계하면 X
// 어느 출입구에서 출발했는지는 중요하지 않으므로, 탐색 시작 시점에서 모든 출입구를 priority queue에 모두 넣는 아이디어 착안이 중요
// 이 경우 시간 복잡도는 O(N+n log n) = O(n log n)이므로, 한 정점에서 모든 정점으로의 최단 경로를 구하는 다익스트라의 정의에 부합

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 인접 리스트로 그래프 관리
vector<pair<int, int>> courses[50001];
vector<int> entrances;
// 모든 출입구에서 각 산봉우리까지의 최단 경로 저장
int dist[50001]; 

bool is_gate(int vertex, vector<int> &gates){
    for(auto g : gates){
        if(g == vertex)
            return true;
    }
    return false;
}

bool is_summit(int vertex, vector<int> &summits){
    for(auto s : summits){
        if(s == vertex)
            return true;
    }
    return false;
}

void find_intensity(vector<int> &gates, vector<int> &summits){
    // 도착 지점 저장 (intensity는 pq에 저장할 필요 x)
    priority_queue<int> pq;
    
    // 모든 출입구를 pq에 저장
    for(auto g : gates){
        pq.push(g);
        dist[g] = 0;
    }
    
    while(!pq.empty()){
        int cur = pq.top();
        pq.pop();
        
        // 현재 지점이 summit이면 탐색 중지
        if(is_summit(cur, summits))
            continue;
        
        for(int i=0; i<courses[cur].size(); i++){
            int next = courses[cur][i].first;
            int next_time = courses[cur][i].second;

            // 다음 지점이 출입구면 dist 업데이트 X
            if(is_gate(next, gates))
                continue;
            
            int intensity = max(dist[cur], next_time);
            if(dist[next] <= intensity) 
                continue;
            
            dist[next] = intensity;
            pq.push(next);
        }
    }
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    // intensity가 최소인 등산 코스가 여러개 => 산봉우리의 번호가 가장 낮은 코스 선택
    // summits를 반드시 정렬해야 함
    sort(summits.begin(), summits.end());
    fill_n(dist, n+1, 987654321);

    for(int i=0; i<paths.size(); i++){
        int a = paths[i][0];
        int b = paths[i][1];
        int duration = paths[i][2];
        
        courses[a].push_back({b, duration});
        courses[b].push_back({a, duration});
    }
    
    find_intensity(gates, summits);
    
    int idx = 0, minimum = 987654321;
    for(auto s : summits){
        if(dist[s] < minimum){
            idx = s;
            minimum = dist[s];
        }   
    }
    
    answer.push_back(idx);
    answer.push_back(minimum);
    return answer;
}
