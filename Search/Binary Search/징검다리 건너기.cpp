// 프로그래머스 LV.3 징검다리 건너기
// 2019 카카오 겨울 인턴십 5번
// 이분탐색 응용

#include <string>
#include <vector> 
#include <iostream>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left = 1;
    int right = 200000000;
    
    answer = left;
    while(left <= right){
        int mid = (left+right) / 2; 
        // mid = 징검다리를 건넌 사람 수
        int dist = 0; // 밟을 수 없는 연속된 디딤돌의 개수
        
        for(int i=0; i<stones.size(); i++){
            if(stones[i] - mid <= 0) // 디딤돌을 밟을 수 없으면
                dist++;
            else // 디딤돌을 밟을 수 있으면
                dist = 0; // 초기화 후 밟을 수 없는 디딤돌 개수 다시 카운트
            
            if(dist >= k) // 건너 뛸 수 있는 최대 간격을 넘으면
                break;
        }
        
        if(dist >= k)
            right = mid-1;
        
        else{
            left = mid+1;
            answer = left;
        }
    }
    
    return answer;
}
