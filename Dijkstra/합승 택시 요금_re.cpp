// 프로그래머스 Lv.3 합승 택시 요금
// 20230819 리팩토링

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 987654321
using namespace std;

void find_lowest(int start, int n, vector<vector<int>>& fees, vector<int>& min_taxi) {
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    min_taxi[start] = 0;
    
    while(!pq.empty()){
        int cost = pq.top().first;
        int current = pq.top().second;
        pq.pop();
        
        // 이미 현재 지점에 대해 최소 요금을 구했다면 continue
        if(min_taxi[current] < cost) continue;
        
        for(int next=1; next<=n; next++){
            // 같은 지점으로 가는 최소 요금은 구하지 않음
            if(fees[current][next] == 0) continue;
            
            int next_cost = fees[current][next] + cost;
            // 지금까지 구한 최소 요금보다 더 적은 경우가 존재하면 업데이트
            if(min_taxi[next] > next_cost) {
                min_taxi[next] = next_cost;
                pq.push(make_pair(next_cost, next));
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    vector<vector<int>> fees(n+1, vector<int>(n+1, 0));
    
    for(int i=0; i<fares.size(); i++) {
        int start = fares[i][0], end = fares[i][1], fee = fares[i][2];
        fees[fares[i][0]][fares[i][1]] = fares[i][2];
        fees[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    
    vector<int> minS(n+1, INF);
    find_lowest(s, n, fees, minS);
    
    vector<int> minA(n+1, INF);
    find_lowest(a, n, fees, minA);
    
    vector<int> minB(n+1, INF);
    find_lowest(b, n, fees, minB);

    // S->i(합승구간) + A->i(A만 이동하는 구간) + B->i(B만 이동하는 구간)의 합이 최소가 되는 지점 
    // = 분기점 구하기
    for(int i=1; i<=n; i++){
        if(minS[i] == INF || minA[i] == INF || minB[i] == INF) continue;
        
        int min_fee = minS[i] + minA[i] + minB[i];
        answer = min(answer, min_fee);
    }
    return answer;
}
