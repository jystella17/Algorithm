// 프로그래머스 Lv.2 요격 시스템

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int solution(vector<vector<int>> targets) {
    int answer = 1;
    sort(targets.begin(), targets.end());
    
    for(int i=0; i<targets.size(); i++){
        if(pq.empty())
            pq.push(targets[i][1]);
        
        else if(pq.top() <= targets[i][0]){ // 요격 미사일이 추가로 필요하다면
            answer++;
            while(!pq.empty()) // 지금까지 요격한 폭격 미사일 목록 삭제
                pq.pop();
            
            pq.push(targets[i][1]); // 앞으로 요격해야 할 폭격 미사일 추가
        }
        else
            pq.push(targets[i][1]);
    }
    return answer;
}
