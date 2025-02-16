// 2025 프로그래머스 코드챌린지 1차 예선 (Lv.1)

#include <vector>
using namespace std;

int convert(int time){
    int hour = (time / 100);
    int minute = (time % 100);
    
    return (hour * 60) + minute;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = schedules.size();
    
    for(int i=0; i<schedules.size(); i++){
        int scheduled = convert(schedules[i]);
        
        for(int j=0; j<7; j++){
            // startday에 따라 주말(토, 일요일) 제거
            if(startday == 1 && (j == 5 || j == 6)) continue;
            else if(startday == 2 && (j == 4 || j == 5)) continue;
            else if(startday == 3 && (j == 3 || j == 4)) continue;
            else if(startday == 4 && (j == 2 || j == 3)) continue;
            else if(startday == 5 && (j == 1 || j == 2)) continue;
            else if(startday == 6 && (j == 0 || j == 1)) continue;
            else if(startday == 7 && (j == 6 || j == 0)) continue;
            
            if(convert(timelogs[i][j]) > scheduled + 10){
                answer--;
                break;
            }
        }
    }
        
    return answer;
}
