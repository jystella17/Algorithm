# 프로그래머스 Lv.2 기능개발
# Queue + 구현

#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<pair<int, int>> works;
    
    for(int i=0; i<progresses.size(); i++)
        works.push(make_pair(i, progresses[i]));
    
    while(!works.empty()){
        int cur_num = works.front().first;
        int cur_progress = works.front().second;
        int deploy = 1; int days = 0;
        
        for(int n=1; n<100; n++){ // 작업 진도는 항상 100 미만이므로, 최소 1일 이상 100일 미만의 추가 작업일 필요
            if(progresses[cur_num] + speeds[cur_num]*n >= 100){
                days = n; break;
            }
        }
        
        for(int i=cur_num+1; i<progresses.size(); i++){
            if(progresses[i] + speeds[i]*days >= 100)
                deploy++; // 현재 작업과 함께 배포할 수 있는 후순위 작업 개수 구하기
            
            if(progresses[i] + speeds[i]*days < 100)
                break; // 함께 배포할 수 없는 작업 발생 시 탐색 종료
    
        }
        
        answer.push_back(deploy);
        while(deploy--)
            works.pop();
    }
    
    return answer;
}
