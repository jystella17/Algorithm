// 프로그래머스 LV.3 외벽 점검
// 2020 카카오 신입 공채 6번
// 순열 + 슬라이딩 윈도우 개념
// 순열을 구하는 대상은 취약 지점이 아닌 친구 목록
// 각 순열 dist의 원소 dist[i]에 대해, i는 현재 취약 지점 점검을 위해 보내는 친구의 번호인 동시에 지금까지 보낸 인원 수로도 볼 수 있음

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 987654321;
    int weak_size = weak.size();
    
    for(int i=0; i<weak_size; i++)
        weak.push_back(weak[i] + n);
    
    sort(dist.begin(), dist.end());
    
    do{ // 슬라이딩 윈도우
        // 윈도우 크기 = 투입하기로 한 친구가 1시간 동안 이동할 수 있는 거리
        for(int i=0; i<weak_size; i++){
            int start = weak[i];
            int end = weak[i + weak_size - 1]; // 외벽 둘레
            
            for(int j=0; j<dist.size(); j++){
                // j = 지금까지 투입한 친구 수 - 1
                start += dist[j]; // 친구 투입 -> 이동 거리 저장
                
                if(start >= end){ // 취약 지점 점검 완료
                    answer = min(answer, j+1); // 친구 수의 최솟값
                    break;
                }
                
                // 아직 점검할 취약 지점이 남은 경우
                for(int k=i+1; k<i+weak_size; k++){
                    if(weak[k] > start){ // 다음 취약 지점으로 이동
                        start = weak[k];
                        break;
                    }
                }
            }
        }
        
    }while(next_permutation(dist.begin(), dist.end()));
    // 점검을 위해 보내는 친구의 조합 
    
    if(answer == 987654321)
        return -1;
    
    else
        return answer;
}
