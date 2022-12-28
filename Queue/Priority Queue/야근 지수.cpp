// 프로그래머스 LV.3 야근 지수
// Priority Queue (Max Heap)을 사용한 풀이
// Greedy 개념

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    // 남은 작업량을 저장하는 max heap
    priority_queue<int> max_works(begin(works), end(works));
    
    // 퇴근까지 남은 n시간 동안 
    // 1시간 단위로 이번 시간에 처리해야 하는 일을 찾기
    while(n){
        // 이번 시간에 처리해야 하는 일 = 남은 작업량이 가장 많은 일
        int maximum_remain = max_works.top();
        
        // 모든 일을 다 처리했다면 시간이 남았어도 탐색 종료
        if(maximum_remain == 0)
            break;
        
        // 작업량이 남은 일이 있는 경우
        // 1. 남은 작업량을 1 감소시킨 후 다시 우선순위 큐에 push
        // 2. 퇴근까지 남은 시간 1 감소
        max_works.pop();
        max_works.push(maximum_remain - 1);
        n--;
    }
    
    while(!max_works.empty()){
        int cur = max_works.top();
        answer += (cur * cur);
        max_works.pop();
    }
    
    return answer;
}
