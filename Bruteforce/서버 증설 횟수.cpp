// 2025 프로그래머스 코드챌린지 2차 예선 - 서버 증설 횟수 (Lv.2)

#include <vector>
#include <iostream>
using namespace std;

int servers[24];

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    for(int i=0; i<players.size(); i++){
        // diff = 이번 시간대에 게임을 이용 중인 인원 - 현재 가동 중인 서버들로 수용 가능한 인원
        int diff = (players[i] - servers[i]*m);

        if(diff >= m){ // 서버 증설이 필요한 경우
            answer += (diff / m); // 증설해야 하는 서버 개수만큼 서버 증설 횟수 증가
            
            for(int j=0; j<k; j++){
                if(i+j >= 24) continue;
                    
                servers[i+j] += (diff / m); // 현재부터 k시간 동안 증설한 서버 유지
            }
         }
    }
    
    return answer;
}
