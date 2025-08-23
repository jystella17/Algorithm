// 프로그래머스 Lv.2 기능개발

#include <cmath>
#include <vector>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> deploy_date, answer;
    int functions = speeds.size(), eod = 1;

    // 각 기능 개발이 오늘로부터 며칠 후에 완료되는지 구하기
    for(int i=0; i<functions; i++){
        int date = ceil(double(100-progresses[i])/double(speeds[i]));
        
        deploy_date.push_back(date);
        eod = max(eod, date);
    }
    
    int last_deployed = -1; // 가장 최근에 배포된 기능들의 마지막 index
    for(int i=1; i<=eod; i++){
        int count = 1;

        // 오늘로부터 i일 후에 배포할 수 있는 기능의 개수 count
        while((count + last_deployed) < functions){
            if(deploy_date[count + last_deployed] > i) break;
            count++;
        }
        
        if(count == 1) continue;
        
        answer.push_back(count-1);
        last_deployed += (count-1);
    }
    
    return answer;
}
