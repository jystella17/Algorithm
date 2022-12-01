// 프로그래머스 Lv.3 광고 삽입
// 2021 카카오 신입공채 1차 5번
// 누적합 & 슬라이딩 윈도우

#include <string>
#include <vector>
#include <algorithm>
#define MAX 360000
using namespace std;

int Time_To_Second(string time){
    int hour = stoi(time.substr(0,2)) * 3600;
    int minute = stoi(time.substr(3,2)) * 60;
    int second = stoi(time.substr(6,2));
    
    return hour+minute+second;
}

string Second_To_Time(int sec){
    string hour = to_string(sec/3600);
    if(hour.size() == 1)
        hour.insert(0, "0");
        
    string minute = to_string((sec%3600)/60);
    if(minute.size() == 1)
        minute.insert(0, "0");
    
    string second = to_string(sec%60);
    if(second.size() == 1)
        second.insert(0, "0");
    
    string time = hour+":"+minute+":"+second;
    return time;
}

string solution(string play_time, string adv_time, vector<string> logs){
    string answer = "";
    vector<int> sum_playTime(MAX, 0);
    
    for(int i=0; i<logs.size(); i++){ // 동영상 누적 재생시간 구하기
        int start = Time_To_Second(logs[i].substr(0,8));
        int end = Time_To_Second(logs[i].substr(9,8));
        
        for(int t=start; t<end; t++)
            sum_playTime[t]++; 
        // 특정 초에 동영상을 시청한 사람이 1명 있다면 sum_playTime[x] = 1
        // 모든 초에 동영상을 1명씩 시청했다면 누적 재생시간은 359999
        // =>특정 초에 동영상을 시청한 인원 = 누적 재생시간에 더해지는 시간(초)
    }
    
    // 동영상의 총 재생시간, 광고 재생시간
    int videoLen = Time_To_Second(play_time);
    int advLen = Time_To_Second(adv_time);
    
    // 가장 적합한 광고 위치 구하기
    // 동영상 길이 == 광고 길이 -> 00:00:00초에 시작할 수밖에 없음
    if(videoLen == advLen)
        answer = Second_To_Time(0);
    
    // 동영상길이 != 광고 길이
    long long sum = 0;
    long long max_time = 0;
    long long result = 0;
    
    // 00:00:00초에 광고를 삽입할 때 누적 재생시간 구하기
    for(int i=0; i<advLen; i++)
        sum += sum_playTime[i];
    
    // sliding window로 play_time 한도 내에서 최대 누적합 구하기
    max_time = sum;
    for(int i=advLen; i<videoLen; i++){
        sum -= sum_playTime[i-advLen]; // 이전 턴의 시작 시점 기록 제거
        sum += sum_playTime[i]; // 이번 턴의 종료 시점 기록 추가
        
        if(sum > max_time){ // 현재 구간의 누적 재생 시간이 더 많다면
            max_time = sum;
            result = i - advLen + 1;
        }
    }
    
    answer = Second_To_Time(result);
    return answer;
}
